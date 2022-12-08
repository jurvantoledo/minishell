/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_dollar.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 12:14:49 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/08 13:19:53 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	expand_dollar(char *input)
{
	t_env	*env;
	char	*new_input;
	int		i;

	while (input[i])
	{
		if (input[i] == '$')
		{
			i++;
			new_input = get_env_arg(&input[i]);
			env = get_env(g_shell.env, new_input);
			if (!env)
			{
				// ft_putstr_fd("", STDOUT_FILENO);
				return (0);
			}
			ft_putstr_fd(env->value, STDOUT_FILENO);
		}
		i++;
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (1);
}
