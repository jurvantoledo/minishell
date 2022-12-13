/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 12:10:26 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/13 17:26:25 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_expanded_exit(char *input)
{
	char	*exit_code;
	int		i;

	exit_code = NULL;
	i = 0;
	while (input[i])
	{
		if (input[i] == '$' && input[i + 1] == '?')
		{
			exit_code = ft_itoa(g_shell.exit_code);
		}
		i++;
	}
	return (exit_code);
}

static char	*ft_get_env_val(char *input)
{
	t_env	*env;
	char	*exit_code;
	int		i;

	if (ft_expanded_exit(input) != NULL)
		return (ft_expanded_exit(input));
	i = 0;
	while (input[i])
	{
		if (input[i] == '$')
		{
			i++;
			env = get_env(g_shell.env, &input[i]);
			if (!env)
				return (input);
			return (env->value);
		}
		i++;
	}
	return (input);
}

static char	*ft_get_dollar_val(char *input)
{
	char	*new_str;
	int		i;

	new_str = ft_calloc(sizeof(char *), 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while ((input[i] && !ft_isspace(input[i])) \
		&& input[i] != '\"')
	{
		new_str[i] = input[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static char	*ft_set_res(char *input)
{
	int		i;
	int		j;
	char	*new_str;
	char	*env_val;
	char	*new_inp;

	i = 0;
	while (input[i] && input[i] != '\'')
	{
		j = 0;
		if (input[i] == '$')
		{
			new_str = ft_get_dollar_val(&input[i]);
			printf("the new dollar string: %s\n", new_str);
			env_val = ft_get_env_val(new_str);
			if (env_val)
			{
				input = ft_replace(input, new_str, env_val);
				if (!input)
					return (NULL);
				printf("die kut input na expanden: %s\n", input);
			}
			free(new_str);
		}
		i++;
	}
	return (input);
}

char	*expand_dollar(char *input)
{
	char	*lol;

	lol = ft_set_res(input);
	printf("lol: %s\n", lol);
	return (lol);
}
