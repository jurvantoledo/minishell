/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 15:43:51 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/09/21 17:10:43 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_double_quotes(char *input)
{
	int	i;

	i = 1;
	while (input[i] && input[i] != '\"')
	{
		printf("%d -> [%c]\n", i, input[i]);
		i++;
	}
	return (i - 1);
}

//1. input checken op de 1e dquote.
//2. itereren totdat je een 2e dquote vindt.
//3. datgene dat tussen die 2 dquotes staat opslaan in struct
