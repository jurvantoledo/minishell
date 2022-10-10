/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_files.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/30 16:54:30 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/07 15:22:12 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	add_to_infile_list(t_infile **head, char *infile, t_token_type type)
{
	t_infile	*tmp;
	t_infile	*new;

	new = ft_calloc(sizeof(t_infile), 1);
	if (!new)
		return (0);
	if (type == 3)
		new->heredick = infile;
	else
		new->infile = infile;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

static int	add_to_outfile_list(t_outfile **head, char *outfile, \
								t_token_type type)
{
	t_outfile	*tmp;
	t_outfile	*new;

	new = ft_calloc(sizeof(t_outfile), 1);
	if (!new)
		return (0);
	if (type == 2)
		new->out_append = outfile;
	else
		new->outfile = outfile;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

int	check_files(char *input, t_lexer *lexer, t_infile *in, t_outfile *out)
{
	char	*file;

	if (lexer->type == 0 || lexer->type == 3)
	{
		file = ft_substr(input, lexer->next->index, lexer->next->length);
		if (!file)
			return (0);
		if (add_to_infile_list(&in, file, lexer->type) == 0)
			return (0);
		free(file);
	}
	if (lexer->type == 1 || lexer->type == 2)
	{
		file = ft_substr(input, lexer->next->index, lexer->next->length);
		if (!file)
			return (0);
		if (add_to_outfile_list(&out, file, lexer->type) == 0)
			return (0);
		free(file);
	}
	print_file_list(in, out);
	return (1);
}
