/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 14:41:24 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/04 12:34:33 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_redirections(char *input, t_lexer *lexer)
{
	char		*infile;

	while (lexer->next != NULL)
	{
		check_files(input, lexer);
		lexer = lexer->next;
	}
}

void	ft_paraser(char *input, t_lexer *lexer)
{
	ft_redirections(input, lexer);
	parse_cmds(input, lexer);
	return ;
}
