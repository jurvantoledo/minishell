/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_echo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 10:41:17 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/01 17:25:35 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	echo_exit(char *arg)
{
	if (ft_strncmp(arg, "$?", 3) == 0)
	{
		ft_putnbr_fd(g_shell.exit_code, 1);
		return (1);
	}
	return (0);
}

static int	check_golfje(char *arg)
{
	t_env	*dir;

	if (ft_strncmp(arg, "~", 2) == 0)
	{
		dir = get_env(g_shell.env, "HOME");
		if (!dir)
			return (0);
		ft_putstr_fd(dir->value, 1);
		return (1);
	}
	return (0);
}

static bool	ft_newline(char *args)
{
	int	i;

	i = 1;
	if (args[0] != '-')
		return (false);
	while (args[i])
	{
		if (args[i] != 'n')
		{
			return (false);
		}
		i++;
	}
	return (true);
}

static void	print_all(int argc, char **args, int i)
{
	while (args[i])
	{
		if (!echo_exit(args[i]) && !check_golfje(args[i]) \
			&& !check_arg_env(args[i]))
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1])
				ft_putchar_fd(' ', 1);
		}
		else
			ft_putchar_fd(' ', 1);
		i++;
	}
}

int	builtin_echo(int argc, char **args)
{
	int		i;
	bool	newline;

	newline = true;
	i = 1;
	if (argc == 1)
	{
		ft_putchar_fd('\n', 1);
		return (0);
	}
	while (args[i] && ft_newline(args[i]) && argc >= 2)
	{
		i++;
	}
	if (i > 1)
		newline = false;
	print_all(argc, args, i);
	if (newline)
		ft_putchar_fd('\n', 1);
	return (1);
}
