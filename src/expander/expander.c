/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 12:10:26 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/09 15:46:19 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*ft_get_env_val(char *input)
{
	t_env	*env;
	int		i;

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

static char	*get_dollar_val(char *input)
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

static char	*ft_set_res(char *input, char *new_str, char *env_val)
{
	char	*res;

	res = ft_replace(input, new_str, env_val);
	return (res);
}

char	*expand_dollar(char *input)
{
	int		i;
	char	*new_str;
	char	*env_val;
	char	*res;

	i = 0;
	while (input[i])
	{
		if (input[i] == '$')
		{
			new_str = get_dollar_val(&input[i]);
			env_val = ft_get_env_val(new_str);
			if (env_val)
			{
				res = ft_set_res(input, new_str, env_val);
				free(new_str);
				input = res;
			}
		}
		i++;
	}
	return (input);
}
