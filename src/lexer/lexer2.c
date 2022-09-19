/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/16 16:03:19 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/09/19 18:33:56 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token_type	set_type(char *input)
{
	if (ft_strncmp(input, "<<", 3) == 0)
		return (HERE_DOC);
	else if (ft_strncmp(input, ">>", 3) == 0)
		return (OUTFILE_APPEND);
	else if (ft_strncmp(input, "|", 2) == 0)
		return (PIPE);
	else if (ft_strncmp(input, "<", 2) == 0)
		return (INFILE);
	else if (ft_strncmp(input, ">", 2) == 0)
		return (OUTFILE);
	else
		return (COMMAND);
}

int	ft_wrlength(char *input)
{
	int		i;
	int		count;
	char	*buf;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (!ft_isspace(input[i]))
		{
			count++;
			printf("%d\n", count);
		}
		else
			count = 0;
		i++;
	}
	return (count);
}

void	ft_snorlexer(char *input)
{
	t_lexer	*lexer;
	t_lexer	*head;
	int		i;

	lexer = ft_calloc(sizeof(t_lexer), 1);
	if (!lexer)
		return ;
	head = lexer;
	lexer->length = ft_wrlength(input);
	i = 0;
	while (input[i])
	{
		if (input[i])
		{
			lexer->next = ft_calloc(sizeof(t_lexer), 1);
			lexer = lexer->next;
		}
		i++;
	}
	printf("the length of lexer: %d\n", head->length);
}
