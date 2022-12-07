/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 12:03:14 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/07 14:16:25 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	run_builtins(int i)
{
	if (ft_strncmp(g_shell.command[i].arguments[0], "pwd", 4) == 0)
		return (builtin_pwd());
	if (ft_strncmp(g_shell.command[i].arguments[0], "echo", 5) == 0)
		return (builtin_echo(ft_arraylen(g_shell.command[i].arguments), \
					g_shell.command[i].arguments));
	if (ft_strncmp(g_shell.command[i].arguments[0], "env", 4) == 0)
		return (builtin_env(ft_arraylen(g_shell.command[i].arguments), \
					g_shell.command[i].arguments));
	if (ft_strncmp(g_shell.command[i].arguments[0], "unset", 6) == 0)
		return (builtin_unset(ft_arraylen(g_shell.command[i].arguments), \
					g_shell.command[i].arguments));
	if (ft_strncmp(g_shell.command[i].arguments[0], "export", 7) == 0)
		return (builtin_export(ft_arraylen(g_shell.command[i].arguments), \
					g_shell.command[i].arguments));
	if (ft_strncmp(g_shell.command[i].arguments[0], "exit", 5) == 0)
		return (builtin_exit(ft_arraylen(g_shell.command[i].arguments), \
					g_shell.command[i].arguments));
	if (ft_strncmp(g_shell.command[i].arguments[0], "cd", 3) == 0)
		return (builtin_cd(ft_arraylen(g_shell.command[i].arguments), \
					g_shell.command[i].arguments));
	if (ft_strncmp(g_shell.command[i].arguments[0], "./minishell", 12) == 0)
		return (set_shlvl());
	if (expand_dollar(g_shell.command[i].arguments[0]))
		return (1);
	return (0);
}

int	exec_builtins(int i)
{	
	if (run_builtins(i) != 0)
		return (0);
	return (errors("minishell", g_shell.command[i].arguments[0], \
			"Command not found", 127));
}
