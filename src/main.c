/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:38:46 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/16 17:43:19 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_shell	g_shell;

int	clean_shell(void)
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

int	main(int argc, char *argv[], char *envp[])
{
	char			*input;

	g_shell.env = parse_env(envp);
	initialize();
	if (!set_shlvl())
		return (0);
	while (1)
	{
		// init_signal();
		input = readline(SHELL_NAME);
		if (!input)
			return (0);
		g_shell.lexer = ft_snorlexer(input);
		if (!g_shell.lexer)
			g_shell.lexer = NULL;
		ft_paraser(input, g_shell.lexer);
		resolve_path();
		ft_exeggutor();
		add_history(input);
		free(input);
		input = NULL;
	}
	return (0);
}
