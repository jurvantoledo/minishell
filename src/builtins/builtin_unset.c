/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_unset.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:38:42 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/15 15:55:45 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	builtin_unset(int argc, char **args)
{
	int		i;

	(void)argc;
	if (!g_shell.env)
		return (1);
	i = 1;
	while (args[i])
	{
		if (!remove_node(&g_shell.env, args[i]))
			return (errors("minishell", args[i], "not a valid identifier", 1));
		i++;
	}
	return (0);
}
