/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 12:10:26 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/21 16:21:50 by jvan-tol      ########   odam.nl         */
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
			g_shell.expanded_exit = true;
			if (!exit_code)
			{
				free(exit_code);
				return (NULL);
			}
		}
		i++;
	}
	return (exit_code);
}

static char	*ft_get_env_val(char *input)
{
	bool	exit_code;
	int		i;

	i = 0;
	exit_code = false;
	while (input[i])
	{
		if (input[i] == '$' && input[i + 1] == '?')
			exit_code = true;
		else if (input[i] == '$')
		{
			i++;
			return (get_env_dollar(&input[i]));
		}
		i++;
	}
	if (exit_code)
		return (ft_expanded_exit(input));
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
		&& (input[i] != '\"' && input[i] != '=') && \
		(input[i] != '<' && input[i] != '>') && \
		(ft_strncmp(input, ">>", 2) != 0 && ft_strncmp(input, "<<", 2) != 0) \
		&& (input[i] != '\''))
	{
		new_str[i] = input[i];
		i++;
		if (input[i] == '$')
			break ;
	}
	new_str[i] = '\0';
	return (new_str);
}

static char	*ft_set_res(char *input)
{
	int		i;
	char	*dollar_val;
	char	*env_val;
	bool	expand;

	i = 0;
	expand = true;
	while (input[i] && expand)
	{
		expand = check_expander(&input[i]);
		g_shell.expanded_exit = false;
		if (input[i] == '$')
		{
			dollar_val = ft_get_dollar_val(&input[i]);
			env_val = ft_get_env_val(dollar_val);
			input = ft_replace(input, dollar_val, env_val);
			if (!input)
				return (NULL);
			if (g_shell.expanded_exit)
				free(env_val);
			free(dollar_val);
		}
		i++;
	}
	return (input);
}

char	*expand_dollar(char *input)
{
	char	*lol;

	lol = ft_set_res(input);
	if (!lol)
		return (NULL);
	return (lol);
}
