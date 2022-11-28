/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 15:43:51 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/28 17:18:20 by jvan-tol      ########   odam.nl         */
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
		else if (input[i] == '|' || input[i] == '>' || input[i] == '<')
			return (1);
		i++;
	}
	return (0);
}

int	ft_add_adjacent(char *input, int i, int len)
{
	char	*new;

	printf("the i in adjacent: %d\n", i);
	new = ft_calloc(sizeof(char *), 1);
	while (input[i])
	{
		printf("%c\n", input[i]);
		i++;
	}
	
	printf("len in adjacent: %d\n", len);
}

void	remove_quotes(char *input, char ch)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		if (input[i] != ch)
		{
			j = i;
			while (input[j])
			{
				input[j] = input[j + 1];
				j++;
			}
			i--;
		}
		i++;
	}
	printf("the length of new string: %d\n", j);
}

static int	ft_lexer_wrlength(char *input)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (input[i] && special_chars(input[i]) == 0)
	{
		if (input[i] == '\"')
		{
			len = check_quotes(&input[i], search_end_quote(&input[i]));
			if (len == 0)
				break ;
			i += len;
			break ;
		}
		else if (ft_isspace(input[i]))
			break ;
		i++;
	}
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
