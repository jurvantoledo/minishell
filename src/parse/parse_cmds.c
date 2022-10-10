/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cmds.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:15:23 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/07 14:46:44 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	get_cmds(char *input, t_lexer *lexer)
{
	t_command	*cmd;
	char		*str;

	cmd = NULL;
	while (lexer != NULL)
	{
		if (lexer->type == 6)
		{
			str = ft_substr(input, lexer->index, lexer->length);
			if (!str)
				return (0);
			add_to_cmd_list(&cmd, str);
		}
		lexer = lexer->next;
	}
	print_cmd_list(cmd);
	return (1);
}
