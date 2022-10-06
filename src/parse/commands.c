/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:15:23 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/06 14:24:27 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_commands(char *input, t_lexer *lexer)
{
	t_command	*cmd;
	char		*new_input;
	char		**split_input;

	cmd = NULL;
	while (lexer != NULL)
	{
		if (lexer->type == 6)
		{
			new_input = ft_substr(input, lexer->index, lexer->length);
			split_input = ft_split(new_input, '-');
			printf("the splitted command %s\n", split_input[0]);
		}
		lexer = lexer->next;
	}
}
