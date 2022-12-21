/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_export_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 15:20:36 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/21 16:44:45 by jvan-tol      ########   odam.nl         */
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

	i = 0;
	if (ft_isdigit(args[0]) || args[0] == '=')
	{
		errors("minishell", args, " not a valid identifier", 1);
		return (0);
	}
	while (args[i] != '=')
	{
		if (!ft_isalpha(args[i]) && !ft_isdigit(args[0]) && args[i] != '_')
		{
			errors("minishell", args, " not a valid identifier", 1);
			return (0);
		}
		i++;
	}
	return (1);
}
