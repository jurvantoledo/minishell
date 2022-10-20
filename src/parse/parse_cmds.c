/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cmds.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:15:23 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/20 16:15:41 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	command_counter(t_lexer *lexer)
{
	int	count;

	count = 0;
	while (lexer != NULL)
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

	count = 1;
	while (lexer && (lexer->type == ARGUMENT || lexer->type == COMMAND))
	{
		// if (lexer->type == ARGUMENT)
		count++;
		lexer = lexer->next;
	}
	printf("count %d \n", count);
	return (count);
}

// char	**parse_args(char *input, t_lexer *lexer, int arg_len)
// {
// 	char	*str;
// 	char	**args;
// 	int		i;

// 	i = 0;
// 	args = ft_calloc(arg_len, sizeof(char *));
// 	if (!args)
// 		return (NULL);
// 	while (lexer && i < arg_len)
// 	{
// 		if (lexer->type == ARGUMENT || lexer->type == COMMAND)
// 		{
// 			str = ft_substr(input, lexer->index, lexer->length);
// 			if (!str)
// 				return (NULL);
// 			args[i] = str;
// 			i++;
// 		}
// 		lexer = lexer->next;
// 	}
// 	args[i] = 0;
// 	return (args);
// }

char	**parse_args(char *input, t_lexer *lexer, int arg_len)
{
	char	*str;
	char	**args;
	int		i;

	i = 0;
	args = ft_calloc(arg_len, sizeof(char *));
	if (!args)
		return (NULL);
	while (lexer && (lexer->type == ARGUMENT || lexer->type == COMMAND))
	{
		str = ft_substr(input, lexer->index, lexer->length);
		if (!str)
			return (NULL);
		args[i] = str;
		i++;
		lexer = lexer->next;
	}
	args[i] = 0;
	return (args);
}

void	parse_cmds(char *input, t_lexer *lexer)
{
	int			arg_len;
	int			i;

	g_shell.cmd_len = command_counter(lexer);
	g_shell.command = ft_calloc(sizeof(t_command), g_shell.cmd_len);
	if (!g_shell.command)
		return ;
	i = 0;
	while (lexer)
	{
		if (lexer->type == COMMAND)
		{
			arg_len = arg_counter(lexer);
			g_shell.command[i].arguments = parse_args(input, lexer, arg_len);
			if (!g_shell.command[i].arguments)
				return ;
			i++;
		}
		lexer = lexer->next;
	}
}
