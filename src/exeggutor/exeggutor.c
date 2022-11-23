/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exeggutor.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 18:19:59 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/23 11:38:14 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_exec(int i)
{
	if (!g_shell.command[i].arguments || \
		g_shell.fd_in < 0 || g_shell.fd_out < 0)
		exit(1);
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
	if (g_shell.cmd_len > 1 && g_shell.command[i].path == NULL && \
		!arg_files_permission())
		exit(exec_builtins(i));
	execve(g_shell.command[i].path, g_shell.command[i].arguments, set_env());
	errors("minishell", g_shell.command[i].arguments[0], \
				"Command not found", 127);
	return (1);
}

static int	child_process(int i)
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
		if ((size_t)i < g_shell.cmd_len - 1)
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

static int	exec_func(void)
{
	int	i;
	int	j;
	int	status;

	i = 0;
	while (i < g_shell.cmd_len)
	{
		if (!child_process(i))
			return (0);
		i++;
	}
	sig_ignore();
	ft_wait();
	g_shell.exit_code = WEXITSTATUS(status);
	sig_handler_exec(status);
	exit(EXIT_FAILURE);
	return (1);
}

static int	single_builtin(void)
{
	if (arg_files_check(g_shell.command[0].arguments[0]) == 1)
	{
		return (arg_files_permission());
		return (1);
	}
	else
	{
		exec_builtins(0);
		return (1);
	}
	return (0);
}

int	ft_exeggutor(void)
{
	int	status;

	if (g_shell.cmd_len == 0)
		return (0);
	else if (g_shell.cmd_len == 1 && g_shell.command[0].path == NULL \
		&& single_builtin())
		return (1);
	if (!ft_fork(&g_shell.pid))
		return (false);
	if (g_shell.pid == 0 && !exec_func())
		return (false);
	sig_ignore();
	waitpid(g_shell.pid, &status, 0);
	if (WIFEXITED(status))
		g_shell.exit_code = WEXITSTATUS(status);
	return (1);
}
