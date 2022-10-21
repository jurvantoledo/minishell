/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exeggutor.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 18:19:59 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/21 12:07:08 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

static void	ft_exec(int i)
{
	if (i == 0 && g_shell.fd_in != STDIN_FILENO)
	{
		dup2(g_shell.fd_in, STDIN_FILENO);
		printf("the infile: %d\n", g_shell.fd_in);
		close(g_shell.fd_in);
	}
	if (i == g_shell.cmd_len - 1 && g_shell.fd_out != STDOUT_FILENO)
	{
		printf("the outfile: %d\n", g_shell.fd_out);
		printf("piemel\n");
		dup2(g_shell.fd_out, STDOUT_FILENO);
		close(g_shell.fd_out);
	}
	execve(g_shell.command[i].path, g_shell.command[i].arguments, set_env());
	exec_builtins(i);
}

int	child_process(int i)
{
	int		fd[2];

	if (!ft_pipe(fd))
		return (0);
	if (!ft_fork(&g_shell.pid))
	{
		close(fd[0]);
		close(fd[1]);
		return (0);
	}
	if (g_shell.pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		ft_exec(i);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
	return (1);
}

int	exec_func(void)
{
	int	i;

	i = 0;
	while (i < g_shell.cmd_len - 1)
	{
		if (!child_process(i))
			return (0);
		i++;
	}
	ft_exec(i);
	return (1);
}

void	ft_exeggutor(void)
{
	if (!exec_func())
		return ;
	return ;
}