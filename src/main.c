/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:38:46 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/09/09 10:03:30 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char			*input;

	parse_env(envp);
	while (1)
	{
		input = readline("teringshell: ");
		if (!input)
			exit(EXIT_FAILURE);
		add_history(input);
		ft_snorlexer(input);
		free(input);
		input = NULL;
	}
	return (0);
}
