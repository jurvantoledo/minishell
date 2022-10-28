/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 12:03:14 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/28 13:49:42 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	invalid_cmd(int argc, char *argv)
{
	if (ft_strncmp(argv, "exit", 5) != 0 && ft_strncmp(argv, "unset", 6) != 0 \
		&& ft_strncmp(argv, "export", 7) != 0 && \
		ft_strcmp(argv, "env") != 0 && ft_strncmp(argv, "echo", 5) != 0 && \
		ft_strncmp(argv, "pwd", 4) != 0 && ft_strncmp(argv, "cd", 3) != 0)
	{
		ft_putstr_fd(argv, 1);
		ft_putchar_fd(':', 1);
		ft_putchar_fd(' ', 1);
		ft_putendl_fd("Command not found", 1);
	}
}

void	exec_builtins(void)
{
	if (ft_strncmp(g_shell.command[0].arguments[0], "pwd", 4) == 0)
		builtin_pwd();
	if (ft_strncmp(g_shell.command[0].arguments[0], "echo", 5) == 0)
		builtin_echo(ft_arraylen(g_shell.command[0].arguments), \
					g_shell.command[0].arguments);
	if (ft_strncmp(g_shell.command[0].arguments[0], "env", 4) == 0)
		builtin_env();
	if (ft_strncmp(g_shell.command[0].arguments[0], "unset", 6) == 0)
		builtin_unset(ft_arraylen(g_shell.command[0].arguments), \
					g_shell.command[0].arguments);
	if (ft_strncmp(g_shell.command[0].arguments[0], "export", 7) == 0)
		builtin_export(ft_arraylen(g_shell.command[0].arguments), \
					g_shell.command[0].arguments);
	if (ft_strncmp(g_shell.command[0].arguments[0], "exit", 5) == 0)
		builtin_exit(ft_arraylen(g_shell.command[0].arguments), \
					g_shell.command[0].arguments);
	if (ft_strncmp(g_shell.command[0].arguments[0], "cd", 3) == 0)
		builtin_cd(ft_arraylen(g_shell.command[0].arguments), \
					g_shell.command[0].arguments);
	invalid_cmd(ft_arraylen(g_shell.command[0].arguments), \
				g_shell.command[0].arguments[0]);
}
