/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 14:39:15 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/24 13:32:45 by jvan-tol      ########   odam.nl         */
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

int	ft_iscapital(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c);
	}
	return (0);
}

int	special_chars(char c)
{
	int	j;

	j = 0;
	while (SPECIAL_CHAR[j] || c == '\"' || c == '\'')
	{
		if (c == SPECIAL_CHAR[j] || c == '\"' || c == '\'')
			return (1);
		j++;
	}
	return (0);
}
