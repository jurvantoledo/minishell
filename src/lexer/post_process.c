/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   post_process.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 15:50:11 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/10 17:29:10 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Checken of lexer-type een argument is. dus als lexer->type 6 is
// en lexer->next->type 6 is dan zal die 2de type wss een argument zijn.
static void	check_cmds(t_lexer *lexer)
{
	if (lexer->type == COMMAND && lexer->next->type == COMMAND)
	{
		lexer->next->type = ARGUMENT;
	}
}

void	post_process(char *input, t_lexer *lexer)
{
	t_lexer	*prev_node;

	prev_node = lexer;
	while (lexer->next != NULL)
	{
		if (prev_node->type != INFILE && prev_node->type != OUTFILE \
			&& prev_node->type != HERE_DOC && prev_node->type != OUTFILE_APPEND)
		{
			lexer = lexer->next;
			if (lexer->next == NULL)
				return ;
			check_cmds(lexer);
		}
		if (lexer->type == PIPE)
		{
			lexer = lexer->next;
			if (lexer->next == NULL)
				return ;
			check_cmds(lexer);
		}
		lexer = lexer->next;
		prev_node = lexer;
	}
}
