/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cmds2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 13:39:27 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/14 14:10:45 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// static int	add_to_cmd_list(t_command **head, char **cmd)
// {
// 	t_command	*tmp;
// 	t_command	*new;

// 	new = ft_calloc(sizeof(t_command), 1);
// 	if (!new)
// 		return (0);
// 	new->command = cmd;
// 	new->next = NULL;
// 	if (!*head)
// 		*head = new;
// 	else
// 	{
// 		tmp = *head;
// 		while (tmp->next)
// 			tmp = tmp->next;
// 		tmp->next = new;
// 	}
// 	return (1);
// }

// void	parse_arguments(char *input, t_lexer *lexer, t_command *cmd)
// {
// 	char	*arguments;
// 	char	*str;

// 	arguments = (char *)malloc(sizeof(char));
// 	if (lexer->type == ARGUMENT)
// 	{
// 		str = ft_substr(input, lexer->index, lexer->length);
// 		if (!str)
// 			return ;
// 		arguments = str;
// 		add_to_cmd_list(&cmd, &arguments);
// 		free(str);
// 	}
// }

// void	parse_commands(char *input, t_lexer *lexer, t_command *cmd)
// {
// 	char	*commands;
// 	char	*str;

// 	commands = (char *)malloc(sizeof(char));
// 		if (lexer->type == COMMAND)
// 		{
// 			str = ft_substr(input, lexer->index, lexer->length);
// 			if (!str)
// 				return ;
// 			commands = str;
// 			add_to_cmd_list(&cmd, &commands);
// 			free(str);
// 		}
// }

// void	get_cmds(char *input, t_lexer *lexer)
// {
// 	t_command	*cmd;
// 	char		**commands;

// 	commands = (char **)malloc(sizeof(char *));
// 	cmd = NULL;
// 	while (lexer != NULL)
// 	{
// 		parse_commands(input, lexer, cmd);
// 		parse_arguments(input, lexer, cmd);
// 		lexer = lexer->next;
// 	}
// 	print_cmd_list(cmd);
// }
