/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 14:39:15 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/09/22 17:25:43 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	update_data(t_lexer *head, int old, int new)
{
	t_lexer	*lexer;

	if (head == NULL)
	{
		printf("Linked List not initialized");
		return ;
	}

	lexer = head;
	while (lexer != NULL)
	{
		if (lexer->type == old)
		{
			lexer->type = new;
			// printf("old found: %d changed to new %d\n", old, new);
			return ;
		}
		lexer = lexer->next;
	}

	printf("%d does not exist in the list\n", old);
}

void	print_list(t_lexer *head)
{
	while (head != NULL)
	{
		printf("index: %d\t lenght: %d\t type: %d\n", head->index, \
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
