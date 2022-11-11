/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 12:03:14 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/11 17:46:35 by jvan-tol      ########   odam.nl         */
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
		return (1);
	}
	return (0);
}

int	print_err(int i)
{
	if (invalid_cmd(ft_arraylen(g_shell.command[i].arguments), \
					g_shell.command[i].arguments[0]) == 1)
		return (errors("minishell", g_shell.command[i].arguments[0], \
				"Command not found", 127));
	return (0);
}

int	exec_builtins(int i)
{
	if (ft_strncmp(g_shell.command[i].arguments[0], "pwd", 4) == 0)
		builtin_pwd();
	if (ft_strncmp(g_shell.command[i].arguments[0], "echo", 5) == 0)
		builtin_echo(ft_arraylen(g_shell.command[i].arguments), \
					g_shell.command[i].arguments);
	if (ft_strncmp(g_shell.command[i].arguments[0], "env", 4) == 0)
		builtin_env(ft_arraylen(g_shell.command[i].arguments), \
					g_shell.command[i].arguments);
	if (ft_strncmp(g_shell.command[i].arguments[0], "unset", 6) == 0)
		builtin_unset(ft_arraylen(g_shell.command[i].arguments), \
					g_shell.command[i].arguments);
	if (ft_strncmp(g_shell.command[i].arguments[0], "export", 7) == 0)
		builtin_export(ft_arraylen(g_shell.command[i].arguments), \
					g_shell.command[i].arguments);
	if (ft_strncmp(g_shell.command[i].arguments[0], "exit", 5) == 0)
		builtin_exit(ft_arraylen(g_shell.command[i].arguments), \
					g_shell.command[i].arguments);
	if (ft_strncmp(g_shell.command[i].arguments[0], "cd", 3) == 0)
		builtin_cd(ft_arraylen(g_shell.command[i].arguments), \
					g_shell.command[i].arguments);
	if (ft_strncmp(g_shell.command[i].arguments[0], "./minishell", 12) == 0)
		set_shlvl();
	return (print_err(i));
}
