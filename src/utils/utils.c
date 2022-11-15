/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 14:39:15 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/15 14:02:48 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_list(t_lexer *head)
{
	while (head != NULL)
	{
		printf("index: %d\t length: %d\t type: %d\n", head->index, \
				head->length, head->type);
		head = head->next;
	}
}

int	special_chars(char c)
{
	int	j;

	j = 0;
	while (SPECIAL_CHAR[j])
	{
		if (c == SPECIAL_CHAR[j])
			return (1);
		j++;
	}
	return (0);
}
