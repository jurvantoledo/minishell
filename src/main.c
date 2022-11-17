/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:38:46 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/17 17:01:02 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_shell	g_shell;

static int	clean_shell(void)
{
	if (g_shell.fd_in > 2)
		close(g_shell.fd_in);
	if (g_shell.fd_out > 2)
		close(g_shell.fd_out);
	return (0);
}

static void	initialize(void)
{
	if (g_shell.fd_in > 2)
		close(g_shell.fd_in);
	if (g_shell.fd_out > 2)
		close(g_shell.fd_out);
	g_shell.fd_in = STDIN_FILENO;
	g_shell.fd_out = STDOUT_FILENO;
}

static int	ft_run_shell(char *input)
{
	g_shell.lexer = ft_snorlexer(input);
	if (!g_shell.lexer || !ft_paraser(input, g_shell.lexer) || \
		!resolve_path() || !ft_exeggutor())
	{
		if (!g_shell.lexer)
		{
			g_shell.lexer = NULL;
			free(input);
			return (1);
		}
		free(input);
	}
	free(input);
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
	char			*input;

	(void)argc;
	(void)argv;
	g_shell.env = parse_env(envp);
	if (!g_shell.env)
		return (0);
	if (!set_shlvl())
		return (0);
	while (1)
	{
		initialize();
		// init_signal();
		input = readline(SHELL_NAME);
		// printf("the input wtf: %s\n", input);
		if (!input)
		{
			return (0);
		}
		ft_run_shell(input);
		add_history(input);
	}
	return (0);
}
