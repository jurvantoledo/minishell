/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cmds.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:15:23 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/14 14:18:22 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	add_to_cmd_list(t_command **head, char **cmd)
{
	t_command	*tmp;
	t_command	*new;

	new = ft_calloc(sizeof(t_command), 1);
	if (!new)
		return (0);
	new->command = cmd;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

char	**parse_cmd(char *input, t_lexer *lexer)
{
	char	**commands;
	char	*str_cmd;
	char	*str_arg;

	commands = (char **)malloc(sizeof(char *));
	if (!commands)
		return (NULL);
	str_cmd = ft_substr(input, lexer->index, lexer->length);
	if (!str_cmd)
		return (NULL);
	commands[0] = str_cmd;
	str_arg = ft_substr(input, lexer->next->index, lexer->next->length);
	if (!str_arg)
		return (NULL);
	commands[1] = str_arg;
	return (commands);
}

void	get_cmds(char *input, t_lexer *lexer)
{
	char		**command;
	t_command	*cmd;

	command = (char **)malloc(sizeof(char *));
	if (!command)
		return ;
	cmd = NULL;
	while (lexer != NULL)
	{
		if (lexer->type == COMMAND && lexer->next->type == ARGUMENT)
		{
			command = parse_cmd(input, lexer);
			add_to_cmd_list(&cmd, command);
		}
		lexer = lexer->next;
	}
	print_cmd_list(cmd);
}
