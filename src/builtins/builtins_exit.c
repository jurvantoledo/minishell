/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins_exit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 17:49:02 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/27 17:52:01 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_exit(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_strncmp(argv[i], "exit", 5) == 0)
		{
			exit(EXIT_SUCCESS);
		}
		i++;
	}
}
