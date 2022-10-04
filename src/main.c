/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:38:46 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/04 14:59:36 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char			*input;
	t_shell			shell;

	parse_env(envp);
	while (1)
	{
		input = readline("Dit is echt leuk: ");
		if (!input)
			exit(EXIT_FAILURE);
		add_history(input);
		shell.lexer = ft_snorlexer(input);
		ft_parser(input, shell.lexer);
		free(input);
		input = NULL;
	}
	return (0);
}
