/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cmds2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 13:39:27 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/14 17:12:04 by jvan-tol      ########   odam.nl         */
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

// char	*parse_commands(char *input, t_lexer *lexer)
// {
// 	char	*str;
// 	char	*command;

// 	str = ft_substr(input, lexer->index, lexer->length);
// 	if (!str)
// 		return (NULL);
// 	command = str;
// 	free(str);
// 	return (command);
// }

// void	get_cmds(char *input, t_lexer *lexer)
// {
// 	t_command	*cmd;
// 	char		**commands;

// 	cmd = NULL;
// 	while (lexer != NULL)
// 	{
// 		lexer = lexer->next;
// 	}
// }
