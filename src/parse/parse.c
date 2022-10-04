/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 14:41:24 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/04 14:43:38 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_redirections(char *input, t_lexer *lexer)
{
	t_infile	*in;
	t_outfile	*out;
	char		*infile;

	in = NULL;
	out = NULL;
	while (lexer != NULL)
	{
		check_files(input, lexer, in, out);
		lexer = lexer->next;
	}
}

void	ft_parser(char *input, t_lexer *lexer)
{
	ft_redirections(input, lexer);
	return ;
}
