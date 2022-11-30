/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   post_process.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 15:50:11 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/30 14:08:38 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_cmd_args(char *input, t_lexer *lexer)
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

void	find_adjacent(const char *input, t_lexer *lexer)
{
	if (!ft_strchr("|<> \t", input[lexer->index + lexer->length]) \
		&& input[lexer->index + lexer->length])
		lexer->adjacent = true;
}

char	*ft_is_adjacent(char *input, t_lexer *lexer)
{
	char	*first;
	char	*second;
	char	*new;

	if (lexer->adjacent == true)
	{
		first = ft_substr(input, lexer->index, lexer->length);
		if (!first)
			return (NULL);
		printf("the first string: %s\n", first);
		second = ft_substr(input, lexer->next->index, lexer->next->length);
		if (!second)
			return (NULL);
		printf("the second string: %s\n", second);
		new = ft_strjoin(first, second);
		free(first);
		free(second);
		return (new);
	}
	new = ft_substr(input, lexer->index, lexer->length);
	return (new);
}

void	post_process(char *input, t_lexer *lexer)
{
	while (lexer != NULL)
	{
		if (lexer->next == NULL)
			return ;
		find_adjacent(input, lexer);
		if (check_infile_out(input, lexer) == 0)
			return ;
		if (check_cmd_args(input, lexer) == 0)
			return ;
		lexer = lexer->next;
	}
}
