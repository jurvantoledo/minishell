/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/15 14:39:15 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/20 09:41:09 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_iscapital(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c);
	}
	return (0);
}

int	special_chars(char c)
{
	int	j;

	j = 0;
	while (SPECIAL_CHAR[j] || c == '\"' || c == '\'')
	{
		if (c == SPECIAL_CHAR[j] || c == '\"' || c == '\'')
			return (1);
		j++;
	}
	return (0);
}
