/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   processing.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 14:54:42 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/09/22 17:31:59 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	process_infile(char *input, t_lexer *lexer)
{
	char	*arg;
	int		i;

	i = 0;
	while (input[i])
	{
		while (lexer != NULL)
		{
			if (lexer->type == 0 && input[lexer->index] == input[i])
				update_data(lexer, lexer->next->type, INFILE);
			if (lexer->type == 1 && input[lexer->index] == input[i])
				update_data(lexer, lexer->next->type, OUTFILE);
			lexer = lexer->next;
		}
		i++;
	}
}

void	post_processing(char *input, t_lexer *lexer)
{
	process_infile(input, lexer);
}
