/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 11:55:56 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/12 17:36:29 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_wait(int status)
{
	size_t	i;

	sig_ignore();
	waitpid(g_shell.pid, &status, 0);
	g_shell.exit_code = WEXITSTATUS(status);
	i = 0;
	sig_handler_exec(status);
	while (wait(&status) != -1)
		(void)"hello c:";
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

int	arg_files_permission(int i)
{
	if (access(g_shell.command[i].arguments[0], R_OK) == -1 && \
		arg_files_check(g_shell.command[i].arguments[0]) == 1)
	{
		return (errors("minishell", g_shell.command[i].arguments[0], \
			"Permission denied", 126));
	}
	return (0);
}
