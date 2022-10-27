/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_echo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 10:41:17 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/27 17:45:48 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_echo(int argc, char **args)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	if (argc == 1)
	{
		ft_putchar_fd('\n', 1);
		return ;
	}
	if (ft_strcmp(args[1], "-n") == 0)
	{
		newline = 0;
		i = 2;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (newline == 1)
		ft_putchar_fd('\n', 1);
	return ;
}
