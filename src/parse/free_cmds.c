/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_cmds.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 10:50:15 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/07 10:50:33 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	purge_commands(void)
{
	int	i;
	int	j;

	i = 0;
	while ((size_t)i < g_shell.cmd_len)
	{
		j = 0;
		if (g_shell.command[i].fd_in > 2)
			close(g_shell.command[i].fd_in);
		if (g_shell.command[i].fd_out > 2)
			close(g_shell.command[i].fd_out);
		while (g_shell.command[i].arguments && g_shell.command[i].arguments[j])
		{
			free(g_shell.command[i].arguments[j]);
			j++;
		}
		free(g_shell.command[i].arguments);
		free(g_shell.command[i].path);
		i++;
	}
	free(g_shell.command);
	g_shell.command = NULL;
	g_shell.cmd_len = 0;
}
