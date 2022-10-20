/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_files.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/30 16:54:30 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/20 15:59:02 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parse_in(t_lexer *lexer, char *input)
{
	char	*tmp;

	if (g_shell.fd_in != STDIN_FILENO)
		close(g_shell.fd_in);
	tmp = ft_substr(input, lexer->index, lexer->length);
	if (access(tmp, R_OK) == 0)
		g_shell.fd_in = open(tmp, O_RDONLY);
	free(tmp);
}

void	parse_out(t_lexer *lexer, char *input)
{
	char	*tmp;

	if (g_shell.fd_out != STDOUT_FILENO)
		close(g_shell.fd_out);
	tmp = ft_substr(input, lexer->index, lexer->length);
	if (lexer->type == OUTFILE)
	{
		g_shell.fd_out = open(tmp, O_RDWR | O_CREAT | O_TRUNC, \
						0644);
	}
	if (lexer->type == OUTFILE_APPEND)
	{
		g_shell.fd_out = open(tmp, O_RDWR | O_CREAT | O_APPEND, \
						0644);
	}
	free(tmp);
}

int	check_files(char *input, t_lexer *lexer)
{
	if (lexer->type == INFILE)
		parse_in(lexer, input);
	if (lexer->type == OUTFILE || lexer->type == OUTFILE_APPEND)
		parse_out(lexer, input);
	return (1);
}
