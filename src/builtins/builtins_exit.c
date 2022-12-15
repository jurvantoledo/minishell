/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins_exit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 17:49:02 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/15 15:58:14 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_digit(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (ft_isdigit(c[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	exit_check_args(int argc, char **argv)
{
	if (argc == 1)
	{
		if (ft_strncmp(argv[0], "exit", 5) == 0)
		{
			ft_putendl_fd("exit", 1);
			exit(EXIT_SUCCESS);
		}
		return (1);
	}
	if (argc > 2 && check_digit(argv[1]) != 0)
	{
		ft_putendl_fd("exit: too many arguments", 1);
		return (1);
	}
	return (0);
}

static int	special_case(int j)
{
	int	exit_code;

	exit_code = 256;
	exit_code -= j;
	return (exit_code);
}

static int	exit_num_minus(char *argv)
{
	int	i;
	int	num;
	int	exit_code;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '-')
		{
			i++;
			num = ft_atoi(&argv[i]);
			exit_code = special_case(num);
			return (exit_code);
		}
		else if (check_digit(argv))
		{
			num = ft_atoi(&argv[i]);
			exit_code = num;
			return (exit_code);
		}
		i++;
	}
	return (0);
}

int	builtin_exit(int argc, char **argv)
{
	int	i;

	if (exit_check_args(argc, argv) == 1)
		return (1);
	i = 0;
	while (argv[i])
	{
		if (ft_strncmp(argv[i], "exit", 5) == 0 && check_digit(argv[1]) == 0)
		{
			exit(errors("minishell", argv[i], \
				"numeric argument required", 255));
		}
		else if (exit_num_minus(argv[i]) != 0)
		{
			g_shell.exit_code = exit_num_minus(argv[i]);
			ft_putendl_fd("exit", 1);
			exit(g_shell.exit_code);
			return (g_shell.exit_code);
		}
		i++;
	}
	ft_putendl_fd("exit", 1);
	exit(EXIT_SUCCESS);
	return (0);
}
