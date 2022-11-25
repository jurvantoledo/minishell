/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_files.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/30 16:54:30 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/25 15:20:34 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	parse_in(t_lexer *lexer, char *input, t_command *cmd)
{
	char	*tmp;

	if (cmd->fd_in != STDIN_FILENO || cmd->fd_in < 0)
	{
		close(cmd->fd_in);
		cmd->fd_in = STDIN_FILENO;
	}
	tmp = ft_substr(input, lexer->next->index, lexer->next->length);
	if (!tmp)
		return ;
	printf("the infile: %s\n", tmp);
	if (access(tmp, R_OK) == 0)
		cmd->fd_in = open(tmp, O_RDONLY);
	else
		exit(errors("minishell", tmp, "no such file or directory", 1));
	free(tmp);
}

static void	parse_out(t_lexer *lexer, char *input, t_command *cmd)
{
	char	*tmp;

	if (cmd->fd_out < 0 || cmd->fd_in < 0)
		return ;
	if (cmd->fd_out != STDOUT_FILENO)
	{
		close(cmd->fd_out);
		cmd->fd_out = STDOUT_FILENO;
	}
	tmp = ft_substr(input, lexer->next->index, lexer->next->length);
	if (!tmp)
		return ;
	printf("the outfile: %s\n", tmp);
	if (ft_strncmp(tmp, ">", 2) == 0)
	{
		free(tmp);
		tmp = NULL;
	}
	if (lexer->type == OUTFILE)
	{
		cmd->fd_out = open(tmp, O_RDWR | O_CREAT | O_TRUNC, \
						0644);
	}
	if (lexer->type == OUTFILE_APPEND)
	{
		cmd->fd_out = open(tmp, O_RDWR | O_CREAT | O_APPEND, \
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
	size_t	cmd_index;

	cmd_index = 0;
	while (lexer->next && g_shell.cmd_len)
	{
		// if (lexer->type == HERE_DOC && lexer->next->type == HERE_DOC)
		// 	parse_heredoc(input, lexer);
		if (lexer->type == INFILE && lexer->next->type == INFILE)
			parse_in(lexer, input, &g_shell.command[cmd_index]);
		if ((lexer->type == OUTFILE && lexer->next->type == OUTFILE) \
			|| (lexer->type == OUTFILE_APPEND && \
			lexer->next->type == OUTFILE_APPEND))
			parse_out(lexer, input, &g_shell.command[cmd_index]);
		lexer = lexer->next;
		if (lexer && lexer->type == PIPE && g_shell.cmd_len > cmd_index)
			cmd_index++;
	}
	printf("the command index in parse_files.c: %zu\n", cmd_index);
	return (1);
}
