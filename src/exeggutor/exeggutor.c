/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exeggutor.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 18:19:59 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/11 17:40:56 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_exec(int i)
{
	// set_sigs_exec();
	if (i == 0 && g_shell.fd_in != STDIN_FILENO)
	{
		dup2(g_shell.fd_in, STDIN_FILENO);
		close(g_shell.fd_in);
	}
	if (i == g_shell.cmd_len - 1 && g_shell.fd_out != STDOUT_FILENO)
	{
		dup2(g_shell.fd_out, STDOUT_FILENO);
		close(g_shell.fd_out);
	}
	if (g_shell.command[i].path == NULL)
		exec_builtins(i);
	execve(g_shell.command[i].path, g_shell.command[i].arguments, set_env());
	if (access(g_shell.command[i].arguments[0], R_OK) == -1)
		exit(errors("minishell", g_shell.command[i].arguments[0], \
			"Command not found", 127));
	exit(errors("minishell", g_shell.command[i].arguments[0], \
		"Permission denied", 127));
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
		if (i != g_shell.cmd_len - 1)
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
	if (!g_shell.cmd_len)
		return (0);
	while (i < g_shell.cmd_len - 1)
	{
		if (!child_process(i))
			return (0);
		i++;
	}
	ft_exec(i);
	return (1);
}

static int	single_builtin(void)
{
	exec_builtins(0);
	return (1);
}

int	ft_exeggutor(void)
{
	int		status;

	if (g_shell.cmd_len == 0)
		return (0);
	if (g_shell.cmd_len == 1 && g_shell.command[0].path == NULL && \
		single_builtin())
		return (1);
	if (!ft_fork(&g_shell.pid))
		return (0);
	if (g_shell.pid == 0 && !exec_func())
		return (0);
	waitpid(g_shell.pid, &status, 0);
	return (1);
}
