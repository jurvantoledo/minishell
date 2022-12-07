/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_dollar.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 12:14:49 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/07 14:04:35 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	expand_dollar(char *input)
{
	t_env	*env;
	int		i;

	while (input[i])
	{
		if (input[i] == '$')
		{
			i++;
			env = get_env(g_shell.env, &input[i]);
			if (!env)
				return (0);
			ft_putendl_fd(env->value, STDOUT_FILENO);
			return (1);
		}
		i++;
	}
	return (0);
}
