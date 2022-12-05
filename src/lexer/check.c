/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 15:43:51 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/05 15:43:14 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_symbol_len(char *input)
{
	int	i;

	i = 0;
	while (input[i] && !ft_isspace(input[i]))
	{
		if ((input[i] == '<' && input[i + 1] == '<') || \
			(input[i] == '>' && input[i + 1] == '>'))
			return (2);
		else if (input[i] == '|' || input[i] == '>' || input[i] == '<' || \
			input[i] == '\"' || input[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_lexer_wrlength(char *input)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (input[i] && !ft_isspace(input[i]) && special_chars(input[i]) == 0)
		i++;
	return (i);
}

int	check_input(char *input, int i)
{
	int	len;

	len = 0;
	if (!special_chars(input[i]))
	{
		len = ft_lexer_wrlength(&input[i]);
	}
	else
	{
		len = ft_symbol_len(&input[i]);
	}
	return (len);
}
