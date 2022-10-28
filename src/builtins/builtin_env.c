/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_env.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 15:44:12 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/28 12:18:00 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	builtin_env(void)
{
	char	*str;
	t_env	*env;

	env = g_shell.env;
	if (!env)
		return (0);
	while (env)
	{
		if (env->key && env->value)
		{
			ft_putstr_fd(env->key, 1);
			ft_putchar_fd('=', 1);
			ft_putendl_fd(env->value, 1);
		}
		env = env->next;
	}
	return (1);
}
