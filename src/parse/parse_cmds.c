/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cmds.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:15:23 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/12 12:03:34 by jvan-tol      ########   odam.nl         */
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
	if (cmd)
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

void	parse_cmds(char *input, t_lexer	*lexer)
{
	t_command	*cmd;
	char		*str;
	char		**commands;
	int			i;

	commands = malloc(sizeof(char *));
	if (!commands)
		return ;
	cmd = NULL;
	while (lexer != NULL)
	{
		if (lexer->type == 6)
		{
			str = ft_substr(input, lexer->index, lexer->length);
			commands[0] = str;
			printf("the commands: %s\n", commands[0]);
		}
		else if (lexer->type == 4)
		{
			str = ft_substr(input, lexer->index, lexer->length);
			commands[1] = str;
			printf("the arguments: %s\n", commands[1]);
		}
		lexer = lexer->next;
	}
}
