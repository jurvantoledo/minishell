/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_files.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/30 16:54:30 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/11 10:42:08 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	parse_in(t_lexer *lexer, char *input)
{
	char	*tmp;

	if (g_shell.fd_in != STDIN_FILENO)
		close(g_shell.fd_in);
	tmp = ft_substr(input, lexer->index, lexer->length);
	printf("the inf: %s\n", tmp);
	if (access(tmp, R_OK) == 0)
		g_shell.fd_in = open(tmp, O_RDONLY);
	free(tmp);
}

static void	parse_out(t_lexer *lexer, char *input)
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

static void	ft_heredick(int *pipe, char *heredoc)
{
	char	*tmp;

	while (1)
	{
		ft_putstr_fd("> ", 1);
		tmp = get_next_line(STDIN_FILENO);
		if (!tmp || ft_strncmp(tmp, heredoc, ft_strlen(heredoc)) == 0)
			break ;
		ft_putstr_fd(tmp, pipe[1]);
		free(tmp);
	}
}

static void	parse_heredoc(char *input, t_lexer *lexer)
{
	char	*heredoc;
	int		pipe[2];

	heredoc = ft_substr(input, lexer->next->index, lexer->next->length);
	if (!heredoc || !ft_pipe(pipe))
	{
		free(heredoc);
		return ;
	}
	if (g_shell.fd_in != STDIN_FILENO)
		close(g_shell.fd_in);
	g_shell.fd_in = pipe[0];
	ft_heredick(pipe, heredoc);
	close(pipe[1]);
	free(heredoc);
}

int	parse_files(char *input, t_lexer *lexer)
{
	while (lexer)
	{
		if (lexer->type == HERE_DOC)
			parse_heredoc(input, lexer);
		if (lexer->type == INFILE)
			parse_in(lexer, input);
		if (lexer->type == OUTFILE || lexer->type == OUTFILE_APPEND)
			parse_out(lexer, input);
		lexer = lexer->next;
	}
	return (1);
}
