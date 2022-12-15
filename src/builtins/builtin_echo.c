/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_echo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 10:41:17 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/15 12:32:47 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

static void	print_all(char **args, int i)
{
	while (args[i])
	{
		if (!check_golfje(args[i]))
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
		return (1);
	}
	while (args[i] && ft_newline(args[i]) && argc >= 2)
	{
		i++;
	}
	if (i > 1)
		newline = false;
	print_all(args, i);
	if (newline)
		ft_putchar_fd('\n', 1);
	return (0);
}
