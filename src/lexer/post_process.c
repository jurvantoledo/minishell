/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   post_process.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 15:50:11 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/03 15:59:20 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_cmd_args(char *input, t_lexer *lexer, t_lexer *prev_node)
{
	if (lexer->next == NULL)
		return (0);
	if (lexer->type != INFILE && lexer->type != OUTFILE \
		&& lexer->type != HERE_DOC && lexer->type != OUTFILE_APPEND \
		&& lexer->type != PIPE)
	{
		if (lexer->next->type != INFILE && lexer->next->type != OUTFILE \
			&& lexer->next->type != HERE_DOC && \
			lexer->next->type != OUTFILE_APPEND && lexer->next->type != PIPE)
		{
			lexer->next->type = ARGUMENT;
		}
		return (1);
	}
	return (1);
}

static int	check_infile_out(char *input, t_lexer *lexer)
{
	char	*str;

	str = ft_substr(input, lexer->index, lexer->length);
	if (!str)
		return (0);
	if (lexer->type == INFILE && input[lexer->index] == '<' \
		&& lexer->next->type != OUTFILE)
		lexer->next->type = INFILE;
	else if (lexer->type == HERE_DOC && \
			ft_strncmp(str, "<<", 3) == 0)
		lexer->next->type = HERE_DOC;
	else if (lexer->type == OUTFILE && input[lexer->index] == '>' \
			&& lexer->next->type != INFILE)
		lexer->next->type = OUTFILE;
	else if (lexer->type == OUTFILE_APPEND && \
			ft_strncmp(str, ">>", 3) == 0)
		lexer->next->type = OUTFILE_APPEND;
	return (1);
}

void	post_process(char *input, t_lexer *lexer)
{
	t_lexer	*prev_node;

	while (lexer != NULL)
	{
		prev_node = lexer;
		if (lexer->next == NULL)
			return ;
		if (check_infile_out(input, lexer) == 0)
			return ;
		if (check_cmd_args(input, lexer, prev_node) == 0)
			return ;
		lexer = lexer->next;
	}
}
