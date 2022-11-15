/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:38:46 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/15 16:45:19 by jvan-tol      ########   odam.nl         */
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
	if (!set_shlvl())
		return (0);
	while (1)
	{
		// init_signal();
		input = readline(SHELL_NAME);
		if (!input)
			return (0);
		add_history(input);
		g_shell.lexer = ft_snorlexer(input);
		if (!g_shell.lexer)
			g_shell.lexer = NULL;
		ft_paraser(input, g_shell.lexer);
		resolve_path();
		ft_exeggutor();
		free(input);
		input = NULL;
	}
	return (0);
}
