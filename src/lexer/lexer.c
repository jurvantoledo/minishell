/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 15:28:13 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/09/09 11:00:41 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token_type	set_tokens(char *input, char c, int i)
{
	if (c == '|')
		return (PIPE);
	else if (ft_strncmp(input, "<<", 2) == 0)
		return (HERE_DOC);
	else if (ft_strncmp(input, ">>", 2) == 0)
		return (OUTFILE_APPEND);
	else if (c == '<')
		return (INFILE);
	else if (c == '>')
		return (OUTFILE);
	else
		return (COMMAND);
}

void	search_tokens(char *input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (SPECIAL_CHAR[j])
		{
			if (SPECIAL_CHAR[j] == input[i])
				set_tokens(input, input[i], i);
			j++;
		}
		i++;
	}
}

void	ft_snorlexer(char *input)
{
	int		i;

	i = 0;
	search_tokens(input);
	while (input[i])
	{
		i++;
	}
}
