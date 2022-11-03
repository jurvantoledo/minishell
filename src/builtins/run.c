/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:08:57 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/03 17:49:09 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	run_builtins(void)
{
	if (builtin_pwd() == 0)
		return (0);
	return (1);
}
