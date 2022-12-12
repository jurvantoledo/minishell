/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_env.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 15:44:12 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/02 15:53:59 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	builtin_env(int argc, char **argv)
{
	t_env	*env;

	if (argc > 1)
	{
		ft_putstr_fd(argv[1], 1);
		ft_putendl_fd(" :No such file or directory", 1);
		g_shell.exit_code = 127;
		return (127);
	}
	env = g_shell.env;
	if (!env)
		return (1);
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
	return (0);
}
