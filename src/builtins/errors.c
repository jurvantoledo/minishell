/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 12:16:04 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/04 12:23:47 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	errors(char *var, char *str, int exit_code)
{
	ft_putstr_fd(var, 1);
	ft_putstr_fd(": ", 1);
	ft_putendl_fd(str, 1);
	g_shell.exit_code = exit_code;
	return (0);
}
