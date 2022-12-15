/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quotes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/28 13:39:33 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/15 16:42:11 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	handle_single_double_quotes(char *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] == '\'')
		{
			j = i;
			break ;
		}
		i++;
	}
	return (j);
}

int	search_end_quote(char *input)
{
	int	i;
	int	j;

	if (handle_single_double_quotes(input) != 0)
		return (handle_single_double_quotes(input));
	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] == '\"')
		{
			j = i;
			break ;
		}
		i++;
	}
	return (j);
}

int	check_quotes(int end)
{
	int	len;

	len = 0;
	if (end == 0)
		return (0);
	while (len < end)
		len++;
	return (len);
}
