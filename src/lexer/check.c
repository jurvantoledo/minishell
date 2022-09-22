/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 15:43:51 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/09/22 13:48:49 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_quotes(char *input)
{
	int	i;

	if (input[0] == '\"')
	{
		i = 1;
		while (input[i] && input[i] != '\"')
			i++;
	}
	if (input[0] == '\'')
	{
		i = 1;
		while (input[i] && input[i] != '\'')
			i++;
	}
	return (i - 1);
}

void	check_semi_slash(char *input)
{
	int	i;

	i = 0;
	while ((input[i] && input[i] == '\\') || (input[i] && input[i] == ';'))
		i++;
}
