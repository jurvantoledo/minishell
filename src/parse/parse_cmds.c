/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cmds.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:15:23 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/14 18:35:07 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_shell	g_shell;

int	command_counter(t_lexer *lexer)
{
	int	count;

	count = 0;
	while (lexer)
	{
		if (lexer->type == COMMAND)
			count++;
		lexer = lexer->next;
	}
	return (count);
}

int	arg_counter(t_lexer *lexer)
{
	int	count;

	count = 0;
	while (lexer)
	{
		if (lexer->type == ARGUMENT)
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

	args = ft_calloc(sizeof(char *), arg_len);
	i = 0;
	while (lexer && i < arg_len)
	{
		if (lexer->type == ARGUMENT)
		{
			str = ft_substr(input, lexer->index, lexer->length);
			args[i] = str;
			printf("%s\n", args[i]);
		}
		i++;
		lexer = lexer->next;
	}
	return (args);
}

void	get_cmds(char *input, t_lexer *lexer)
{
	int			arg_len;
	int			cmd_len;
	int			i;

	g_shell.cmd_len = command_counter(lexer);
	g_shell.command = ft_calloc(g_shell.cmd_len, sizeof(t_command));
	if (!g_shell.command)
		return ;
	i = 0;
	while (lexer && i < g_shell.cmd_len)
	{
		if (lexer->type == COMMAND)
		{
			arg_len = arg_counter(lexer);
			g_shell.command[i].command = parse_args(input, lexer, arg_len);
			if (!g_shell.command[i].command)
				return ;
			printf("%s\n", g_shell.command[i].command[0]);
			i++;
		}
		lexer = lexer->next;
	}
}
