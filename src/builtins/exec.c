/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 12:03:14 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/26 14:16:01 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_builtins(void)
{
	if (ft_strncmp(g_shell.command[0].arguments[0], "pwd", \
		ft_strlen(g_shell.command[0].arguments[0])) == 0)
		builtin_pwd();
	if (ft_strncmp(g_shell.command[0].arguments[0], "echo", \
		ft_strlen(g_shell.command[0].arguments[0])) == 0)
		builtin_echo();
	if (ft_strncmp(g_shell.command[0].arguments[0], "env", \
		ft_strlen(g_shell.command[0].arguments[0])) == 0)
		builtin_env();
	if (ft_strncmp(g_shell.command[0].arguments[0], "unset", \
		ft_strlen(g_shell.command[0].arguments[0])) == 0)
		builtin_unset(ft_arraylen(g_shell.command[0].arguments), \
					g_shell.command[0].arguments);
	if (ft_strncmp(g_shell.command[0].arguments[0], "export", \
		ft_strlen(g_shell.command[0].arguments[0])) == 0)
		builtin_export(g_shell.command[0].arguments);
}
