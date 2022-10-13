/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cmds.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:15:23 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/13 18:08:00 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	add_to_cmd_list(t_command **head, char **cmd)
{
	t_command	*tmp;
	t_command	*new;

	new = ft_calloc(sizeof(t_command), 1);
	if (!new)
		return (0);
	// printf("the command in list: %s & the argument in list: %s\n", cmd[0], cmd[1]);
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

void	parse_cmds(char *input, t_lexer *lexer)
{
	char		**command;
	t_command	*cmd;
	char		*str_cmd;
	char		*str_arg;

	command = (char **)malloc(sizeof(char *));
	if (!command)
		return ;
	cmd = NULL;
	while (lexer != NULL)
	{
		if (lexer->type == COMMAND && lexer->next->type == ARGUMENT)
		{
			str_cmd = ft_substr(input, lexer->index, lexer->length);
			if (!str_cmd)
				return ;
			command[0] = str_cmd;
			str_arg = ft_substr(input, lexer->next->index, lexer->next->length);
			if (!str_arg)
				return ;
			command[1] = str_arg;
			add_to_cmd_list(&cmd, command);
		}
		lexer = lexer->next;
	}
	print_cmd_list(cmd);
}

void	get_cmds(char *input, t_lexer *lexer)
{
	char		**command;
	t_command	*cmd;

	cmd = NULL;
	parse_cmds(input, lexer);
}
