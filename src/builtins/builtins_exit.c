/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins_exit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 17:49:02 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/28 17:20:34 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_digit(char *c)
{
	int	i;
	int	x;

	i = 0;
	while (c[i])
	{
		if (ft_isdigit(c[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	builtin_exit(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		if (ft_strncmp(argv[0], "exit", 5) == 0)
		{
			ft_putendl_fd("exit", 1);
			exit(EXIT_SUCCESS);
		}
	}
	if (argc > 2)
	{
		ft_putendl_fd("exit: too many arguments", 1);
		return ;
	}
	i = 0;
	while (argv[i])
	{
		if (ft_strncmp(argv[i], "exit", 5) == 0 && check_digit(argv[1]) == 0)
		{
			ft_putstr_fd("exit: ", 1);
			ft_putstr_fd(argv[1], 1);
			ft_putchar_fd(' ', 1);
			ft_putstr_fd("numeric argument required\n", 1);
			g_shell.exit_code = 0;
			exit(EXIT_SUCCESS);
		}
		else
		{
			ft_putendl_fd("exit", 1);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
}
