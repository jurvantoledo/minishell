/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 15:18:34 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/07 14:38:31 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	add_to_cmd_list(t_command **head, char *cmd)
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

// static int	check_args(char *input)
// {
// 	int	i;

// 	i = 0;
// 	while (input[i])
// 	{
// 		if (input[i] == '$' && input[i + 1] == '?')
// 		{
// 			return (g_shell.exit_code);
// 		}
// 		else if (input[i] == '$' && ft_isspace(input[i + 1]))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	get_args(char *input, t_lexer *lexer)
// {
// 	t_command	*cmd;
// 	char		*args;
// 	char		*dlr_sign;
// 	char		*join;

// 	cmd = NULL;
// 	while (lexer)
// 	{
// 		if (lexer->type == 4 && !check_args(input))
// 		{
// 			dlr_sign = ft_substr(input, lexer->index, lexer->length);
// 			if (!dlr_sign)
// 				return (0);
// 			args = ft_substr(input, lexer->next->index, lexer->next->length);
// 			if (!args)
// 				return (0);
// 			join = ft_strjoin(dlr_sign, args);
// 			if (!join)
// 				return (0);
// 			add_to_cmd_list(&cmd, join, NULL);
// 		}
// 		lexer = lexer->next;
// 	}
// 	print_cmd_list(cmd);
// 	return (0);
// }
