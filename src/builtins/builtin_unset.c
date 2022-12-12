/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_unset.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:38:42 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/07 14:17:18 by jvan-tol      ########   odam.nl         */
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
		remove_node(&g_shell.env, args[i]);
		i++;
	}
	return (0);
}
