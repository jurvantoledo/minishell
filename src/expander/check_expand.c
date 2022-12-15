/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 12:10:26 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/15 17:11:37 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	check_expander(char *input)
{
	int		i;
	bool	expand;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' && input[i + 1] == '\"')
			expand = false;
		else if (input[i] == '\"' && input[i + 1] == '\'')
			expand = true;
		else if (input[i] == '\'')
			expand = false;
		else
			expand = true;
		
		i++;
	}
	return (expand);
}