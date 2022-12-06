/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 15:02:29 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/06 11:10:52 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_char(char **src)
{
	int	i;

	i = 0;
	while (src && src[i])
	{
		free(src[i]);
		i++;
	}
	free(src);
}

void	ft_remove_commands(void)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < g_shell.cmd_len)
	{
		j = 0;
		while (g_shell.command[i].arguments[j])
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
