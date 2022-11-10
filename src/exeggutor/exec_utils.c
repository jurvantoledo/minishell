/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 11:55:56 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/10 13:50:42 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	err_empty_string(char *argv)
{
	ft_putstr_fd("Error: ", 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(argv, 1);
	ft_putchar_fd('\n', 1);
	g_shell.exit_code = 126;
	return (0);
}

int	ft_pipe(int fds[2])
{
	if (pipe(fds) == -1)
		return (0);
	return (1);
}

int	ft_fork(pid_t *pid)
{
	pid_t	output;

	output = fork();
	if (output == -1)
		return (0);
	*pid = output;
	return (1);
}
