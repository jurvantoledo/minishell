/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   post_process.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 15:50:11 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/13 11:01:14 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Checken of lexer-type een argument is. dus als lexer->type 6 is
// en lexer->next->type 6 is dan zal die 2de type wss een argument zijn.
static void	change_commands_args(t_lexer *lexer)
{
	if (lexer->type == COMMAND && lexer->next->type == COMMAND)
		lexer->next->type = ARGUMENT;
}

static int	check_cmd_args(char *input, t_lexer *lexer, t_lexer *prev_node)
{
	if (lexer->next == NULL)
		return (0);
	if (prev_node->type != INFILE && prev_node->type != OUTFILE \
		&& prev_node->type != HERE_DOC && prev_node->type != OUTFILE_APPEND \
		&& prev_node->type != PIPE)
	{
		change_commands_args(lexer);
		return (1);
	}
	if (lexer->type == PIPE && input[lexer->next->next->index] == '-')
	{
		change_commands_args(lexer);
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
	if (lexer->type == INFILE && input[lexer->index] == '<')
		lexer->next->type = INFILE;
	else if (lexer->type == HERE_DOC && \
			ft_strncmp(str, "<<", 3) == 0)
		lexer->next->type = HERE_DOC;
	else if (lexer->type == OUTFILE && input[lexer->index] == '>')
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
		if (check_infile_out(input, lexer) == 0)
			return ;
		if (check_cmd_args(input, lexer, prev_node) == 0)
			return ;
		lexer = lexer->next;
	}
}
