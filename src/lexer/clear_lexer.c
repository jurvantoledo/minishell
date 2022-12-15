/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_lexer.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 11:05:22 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/07 11:56:58 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	clear_token_list(t_lexer **head)
{
	t_lexer	*next;
	t_lexer	*thead;

	thead = *head;
	while (thead)
	{
		next = thead->next;
		free(thead);
		thead = next;
	}
	*head = NULL;
	return (false);
}
