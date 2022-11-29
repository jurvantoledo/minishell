/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:38:46 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/29 13:58:47 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_shell	g_shell;

int	clean_shell(void)
{
	int	i;

	i = 0;
	while (i < g_shell.cmd_len)
	{
		if (g_shell.command[i].fd_in > 2)
			close(g_shell.command[i].fd_in);
		if (g_shell.command[i].fd_out > 2)
			close(g_shell.command[i].fd_out);
		i++;
	}
	return (0);
}

static int	ft_run_shell(char *input)
{
	g_shell.lexer = ft_snorlexer(input);
	if (!g_shell.lexer)
	{
		free(input);
		return (1);
	}
	if (!ft_paraser(input, g_shell.lexer) || !resolve_path() \
		|| !ft_exeggutor())
	{
		free(input);
		exit(EXIT_FAILURE);
	}
	free(input);
	return (1);
}

char	*read_command_line(void)
{
	char	*input;

	input = readline("[terminal cancer]: ");
	if (!input)
	{
		ft_putendl_fd("exit", 1);
		rl_clear_history();
		exit(EXIT_FAILURE);
	}
	if (input && *input)
		add_history(input);
	return (input);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*input;

	rl_catch_signals = 0;
	(void)argc;
	(void)argv;
	g_shell.env = parse_env(envp);
	if (!g_shell.env)
		exit(EXIT_FAILURE);
	if (!set_shlvl())
		exit(EXIT_FAILURE);
	while (1)
	{
		init_signal();
		input = read_command_line();
		ft_run_shell(input);
		clean_shell();
	}
	return (0);
}
