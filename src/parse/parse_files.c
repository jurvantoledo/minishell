/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_files.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/30 16:54:30 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/20 12:07:08 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	parse_in(t_lexer *lexer, char *input, t_command *cmd)
{
	char	*tmp;

	if (cmd->fd_in != STDIN_FILENO || cmd->fd_in < 0)
	{
		close(cmd->fd_in);
		cmd->fd_in = STDIN_FILENO;
	}
	tmp = ft_substr(input, lexer->next->index, lexer->next->length);
	if (!tmp)
		return (false);
	if (access(tmp, R_OK) == 0)
		cmd->fd_in = open(tmp, O_RDONLY);
	else
		errors("minishell", tmp, "no such file or directory", 1);
	free(tmp);
	return (true);
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
	if (lexer->type == OUTFILE && ft_strncmp(tmp, ">", 2) != 0)
		cmd->fd_out = open(tmp, O_RDWR | O_CREAT | O_TRUNC, \
						0644);
	if (lexer->type == OUTFILE_APPEND && ft_strncmp(tmp, ">>", 2) != 0)
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
		{
			free(tmp);
			break ;
		}
		ft_putstr_fd(tmp, pipe[1]);
		free(tmp);
	}
}

static void	parse_heredoc(char *input, t_lexer *lexer, t_command *cmd)
{
	char	*heredoc;
	int		pipe[2];

	heredoc = NULL;
	heredoc = ft_substr(input, lexer->next->index, lexer->next->length);
	if (!heredoc || !ft_pipe(pipe))
	{
		free(heredoc);
		return ;
	}
	if (cmd->fd_in != STDIN_FILENO)
	{
		close(cmd->fd_in);
		cmd->fd_in = STDIN_FILENO;
	}
	cmd->fd_in = pipe[0];
	ft_heredick(pipe, heredoc);
	close(pipe[1]);
	free(heredoc);
}

int	parse_files(char *input, t_lexer *lexer)
{
	size_t	cmd_index;

	cmd_index = 0;
	while (lexer->next != NULL)
	{
		if (lexer->type == HERE_DOC && lexer->next->type == HERE_DOC)
			parse_heredoc(input, lexer, &g_shell.command[cmd_index]);
		if (lexer->type == INFILE && lexer->next->type == INFILE)
			if (!parse_in(lexer, input, &g_shell.command[cmd_index]))
				return (0);
		if ((lexer->type == OUTFILE && lexer->next->type == OUTFILE) || \
		(lexer->type == OUTFILE_APPEND && lexer->next->type == OUTFILE_APPEND))
			parse_out(lexer, input, &g_shell.command[cmd_index]);
		lexer = lexer->next;
		if (lexer && lexer->type == PIPE && g_shell.cmd_len > cmd_index)
			cmd_index++;
	}
	return (1);
}
