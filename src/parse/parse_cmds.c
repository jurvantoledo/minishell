/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cmds.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:15:23 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/08 13:12:13 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	command_counter(t_lexer *lexer)
{
	int	count;

	count = 0;
	if (!lexer)
		return (0);
	while (lexer)
	{
		if (lexer->type == COMMAND)
			count++;
		lexer = lexer->next;
	}
	return (count);
}

static size_t	arg_counter(t_lexer *lexer)
{
	int	count;

	count = 0;
	while (lexer && lexer->type != PIPE)
	{
		if ((lexer->type == ARGUMENT || lexer->type == COMMAND))
			count++;
		lexer = lexer->next;
	}
	return (count);
}

char	**parse_args(char *input, t_lexer *lexer, int arg_len)
{
	char	*str;
	char	**args;
	int		i;

	i = 0;
	args = ft_calloc(arg_len + 1, sizeof(char *));
	if (!args)
		return (NULL);
	while (lexer && i < arg_len)
	{
		while (lexer && (lexer->type != ARGUMENT && lexer->type != COMMAND))
			lexer = lexer->next;
		str = ft_is_adjacent(input, lexer);
		if (!str)
			return (NULL);
		if (lexer->adjacent)
			lexer = lexer->next;
		if (maybe_expand(str))
			return (expanded_args(args, str));
		args[i] = str;
		i++;
		lexer = lexer->next;
	}
	args[i] = 0;
	return (args);
}

int	parse_cmds(char *input, t_lexer *lexer)
{
	int			arg_len;
	size_t		i;

	g_shell.cmd_len = command_counter(lexer);
	g_shell.command = ft_calloc(sizeof(t_command), g_shell.cmd_len);
	if (!g_shell.command)
		return (0);
	i = 0;
	while (lexer && i < g_shell.cmd_len)
	{
		g_shell.command[i].fd_in = STDIN_FILENO;
		g_shell.command[i].fd_out = STDOUT_FILENO;
		arg_len = arg_counter(lexer);
		if (arg_len)
		{
			g_shell.command[i].arguments = parse_args(input, lexer, arg_len);
			if (!g_shell.command[i].arguments)
				return (0);
		}
		while (lexer && lexer->next && lexer->type != PIPE)
			lexer = lexer->next;
		lexer = lexer->next;
		i++;
	}
	return (1);
}
