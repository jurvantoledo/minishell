/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:38:46 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/14 15:08:15 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_shell	g_shell;

int	main(int argc, char *argv[], char *envp[])
{
	char			*input;

	g_shell.env = parse_env(envp);
	while (1)
	{
		input = readline("Dit is echt leuk: ");
		if (!input)
			exit(EXIT_FAILURE);
		add_history(input);
		g_shell.lexer = ft_snorlexer(input);
		ft_parser(input, g_shell.lexer);
		free(input);
		// if (!run_builtins())
		// 	return (0);
		input = NULL;
	}
	return (0);
}
