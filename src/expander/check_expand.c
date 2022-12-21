/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_expand.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 12:10:26 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/21 16:21:55 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	check_expander(char *input)
{
	int		i;
	bool	expand;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' && input[i + 1] == '\"')
			expand = false;
		if (input[i] == '\"' && input[i + 1] == '\'')
			expand = true;
		if (input[i] == '\'')
			expand = false;
		else
			expand = true;
		i++;
	}
	return (expand);
}

char	*get_env_dollar(char *input)
{
	t_env	*env;

	env = get_env(g_shell.env, input);
	if (!env)
	{
		g_shell.expanded_exit = true;
		return (ft_strdup(""));
	}
	return (env->value);
}
