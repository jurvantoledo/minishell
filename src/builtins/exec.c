/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 12:03:14 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/10 13:53:10 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	invalid_cmd(int argc, char *argv)
{
	if (ft_strncmp(argv, "exit", 5) != 0 && ft_strncmp(argv, "unset", 6) != 0 \
		&& ft_strncmp(argv, "export", 7) != 0 && \
		ft_strcmp(argv, "env") != 0 && ft_strncmp(argv, "echo", 5) != 0 && \
		ft_strncmp(argv, "pwd", 4) != 0 && ft_strncmp(argv, "cd", 3) != 0 && \
		ft_strncmp(argv, "./minishell", 12) != 0)
	{
		return (0);
	}
	return (1);
}

void	print_err(int argc, char *argv)
{
	if ((!invalid_cmd(argc, argv) && !expander(argv)) \
		|| g_shell.lexer->length == 0)
	{
		ft_putstr_fd(argv, 1);
		ft_putchar_fd(':', 1);
		ft_putchar_fd(' ', 1);
		ft_putendl_fd("Command not found", 1);
		g_shell.exit_code = 127;
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
		builtin_env(ft_arraylen(g_shell.command[0].arguments), \
					g_shell.command[0].arguments);
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
	if (ft_strncmp(g_shell.command[0].arguments[0], "./minishell", 12) == 0)
		set_shlvl();
	print_err(ft_arraylen(g_shell.command[0].arguments), \
				g_shell.command[0].arguments[0]);
}
