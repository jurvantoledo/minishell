/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 11:55:56 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/20 13:02:57 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_wait(int status)
{
	size_t	i;

	sig_ignore();
	waitpid(g_shell.pid, &status, 0);
	g_shell.exit_code = WEXITSTATUS(status);
	sig_handler_exec(status);
	i = 0;
	while (i < g_shell.cmd_len)
	{
		wait(&status);
		i++;
	}
	exit(clean_shell(NULL, g_shell.exit_code, true));
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

int	arg_files_check(char *arg)
{
	if (ft_strncmp(arg, "./", 2) == 0)
		return (1);
	return (0);
}

void	ft_exec_error(int i)
{
	if (access(g_shell.command[i].arguments[0], F_OK) == 0)
		exit(errors("minishell", g_shell.command[i].arguments[0], \
			"is a directory", 126));
	if (access(g_shell.command[i].arguments[0], F_OK) == -1 && \
		arg_files_check(g_shell.command[i].arguments[0]) == 1)
		exit(errors("minishell", g_shell.command[i].arguments[0], \
			"Permission denied", 126));
	exit(errors("minishell", g_shell.command[i].arguments[0], \
			"Command not found", 127));
}
