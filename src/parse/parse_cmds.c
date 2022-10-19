/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cmds.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:15:23 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/19 14:40:21 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

	i = 0;
	args = ft_calloc(arg_len + 1, sizeof(char *));
	if (!args)
		return (NULL);
	while (lexer && i < arg_len)
	{
		if (lexer->type == ARGUMENT || lexer->type == COMMAND)
		{
			str = ft_substr(input, lexer->index, lexer->length);
			if (!str)
				return (NULL);
			args[i] = str;
			printf("%s\n", args[i]);
			i++;
		}
		lexer = lexer->next;
	}
	args[i] = 0;
	return (args);
}

void	parse_cmds(char *input, t_lexer *lexer)
{
	int			arg_len;
	int			i;

	i = 0;
	g_shell.cmd_len = command_counter(lexer);
	g_shell.command = ft_calloc(g_shell.cmd_len, sizeof(t_command));
	if (!g_shell.command)
		return ;
	while (lexer && i < g_shell.cmd_len)
	{
		if (lexer->type == COMMAND)
		{
			arg_len = arg_counter(lexer);
			// if (!g_shell.command)
			// 	return ;
			g_shell.command[i].arguments = parse_args(input, lexer, arg_len);
			if (!g_shell.command[i].arguments)
				return ;
			i++;
		}
		lexer = lexer->next;
	}
}
