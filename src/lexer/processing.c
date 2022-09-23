/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   processing.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 14:54:42 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/09/23 12:18:54 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	process_in_out(char *input, t_lexer *lexer)
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

static int	check_dollar_sign(char *input, t_lexer *lexer)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '$' && input[i + 1] != ' ')
		{
			update_data(lexer, 6, ARGUMENT);
			return (1);
		}
		i++;
	}
	return (0);
}

void	post_processing(char *input, t_lexer *lexer)
{
	process_in_out(input, lexer);
	if (check_dollar_sign(input, lexer) != 1)
		return ;
}
