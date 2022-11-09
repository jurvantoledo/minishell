/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:38:46 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/09 14:17:09 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_shell	g_shell;

int	main(int argc, char *argv[], char *envp[])
{
	char			*input;

	g_shell.env = parse_env(envp);
	g_shell.fd_in = STDIN_FILENO;
	g_shell.fd_out = STDOUT_FILENO;
	while (1)
	{
		// init_signal();
		input = readline(SHELL_NAME);
		add_history(input);
		g_shell.lexer = ft_snorlexer(input);
		if (!g_shell.lexer)
			return (0);
		ft_paraser(input, g_shell.lexer);
		resolve_path();
		ft_exeggutor();
		free(input);
		input = NULL;
	}
	return (0);
}
