/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 12:03:14 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/21 12:15:57 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_builtins(int i)
{
	printf("the command: %s\n", g_shell.command[i].arguments[0]);
	if (ft_strncmp(g_shell.command[i].arguments[0], "pwd", \
		ft_strlen(g_shell.command[i].arguments[0])) == 0)
		pwd();
	if (ft_strncmp(g_shell.command[i].arguments[0], "echo", \
		ft_strlen(g_shell.command[i].arguments[0])) == 0)
		echo();
}
