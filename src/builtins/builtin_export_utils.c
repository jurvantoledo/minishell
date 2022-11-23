/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_export_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 15:20:36 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/23 12:02:18 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_val_quotes(char *val)
{
	int	i;

	i = 0;
	while (val[i])
	{
		if (val[i] == '\"' || val[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}

int	args_identifier(char *args)
{
	int	i;

	if (ft_strcmp(args, "\"") == 0)
	{
		errors("minishell: ", args, " not a valid identifier", 1);
		return (0);
	}
	if (ft_isdigit(args[0]) && ft_isalpha(args[1]))
	{
		errors("minishell", args, " not a valid identifier", 1);
		return (0);
	}
	return (1);
}
