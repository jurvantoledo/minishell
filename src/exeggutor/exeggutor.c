/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exeggutor.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 18:19:59 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/17 17:15:23 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_exec(int i)
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
	if (g_shell.cmd_len > 1 && g_shell.command[i].path == NULL && \
		!arg_files_permission())
		exit(exec_builtins(i));
	execve(g_shell.command[i].path, g_shell.command[i].arguments, set_env());
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
		if ((size_t)i != g_shell.cmd_len - 1)
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
	int	status;
	int	i;

	i = 0;
	while (i < g_shell.cmd_len)
	{
		if (!child_process(i))
			return (0);
		i++;
	}
	waitpid(g_shell.pid, &status, 0);
	g_shell.exit_code = WEXITSTATUS(status);
	while (wait(&status) != -1)
		(void)"hello c:";
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
		return (exec_builtins(0));
	}
	return (0);
}

int	ft_exeggutor(void)
{
	int		status;

	if (g_shell.command == 0)
		return (1);
	if (g_shell.cmd_len == 1 && g_shell.command[0].path == NULL \
		&& single_builtin())
		return (1);
	if (!ft_fork(&g_shell.pid))
		return (0);
	if (g_shell.pid == 0 && !exec_func())
		return (0);
	waitpid(g_shell.pid, &status, 0);
	if (WIFEXITED(status))
		g_shell.exit_code = WEXITSTATUS(status);
	return (1);
}
