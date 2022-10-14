/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 14:39:15 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/14 17:49:14 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_list(t_lexer *head)
{
	while (head != NULL)
	{
		printf("index: %d\t lenght: %d\t type: %d\n", head->index, \
				head->length, head->type);
		head = head->next;
	}
}

void	print_file_list(t_infile *in_head, t_outfile *out_head)
{
	while (in_head != NULL)
	{
		printf("the infile: %s\n", in_head->infile);
		printf("the heredoc: %s\n", in_head->heredick);
		in_head = in_head->next;
	}
	while (out_head)
	{
		printf("the outfile: %s\n", out_head->outfile);
		printf("the outfile append: %s\n", out_head->out_append);
		out_head = out_head->next;
	}
}

void	print_cmd_list(t_command *head)
{
	while (head != NULL)
	{
		printf("The arguments in head: %s\n", head->command[0]);
		head = head->next;
	}
}

int	special_chars(char c)
{
	int	j;

	j = 0;
	while (SPECIAL_CHAR[j])
	{
		if (c == SPECIAL_CHAR[j])
			return (1);
		j++;
	}
	return (0);
}
