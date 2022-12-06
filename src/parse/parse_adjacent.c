/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_adjacent.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 15:38:17 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/06 15:57:33 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_add_adjacent(char *input, t_lexer *lexer)
{
	char	*first;
	char	*second;
	char	*new;

	if (!lexer)
		return (NULL);
	first = ft_substr(input, lexer->index, lexer->length);
	if (!first)
		return (NULL);
	second = ft_substr(input, lexer->next->index, lexer->next->length);
	if (!second)
		return (NULL);
	new = ft_strjoin(first, second);
	if (!new)
	{
		free(first);
		free(second);
		free(new);
		return (NULL);
	}
	free(first);
	free(second);
	return (new);
}

char	*ft_is_adjacent(char *input, t_lexer *lexer)
{
	char	*new;
	char	*new2;

	if (lexer->adjacent)
		return (ft_add_adjacent(input, lexer));
	new = ft_substr(input, lexer->index, lexer->length);
	if (!new)
		return (NULL);
	return (new);
}
