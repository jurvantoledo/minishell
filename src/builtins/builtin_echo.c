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

int	echo_exit(char *arg)
{
	if (ft_strncmp(arg, "$?", 3) == 0)
	{
		ft_putnbr_fd(g_shell.exit_code, 1);
		return (1);
	}
	return (0);
}

int	check_argcount(int argc)
{
	if (argc == 1)
	{
		ft_putchar_fd('\n', 1);
		return (0);
	}
	return (1);
}

char	*get_env_arg(char *arg)
{
	int		i;
	char	*new;

	new = malloc(sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	while (arg[i] && arg[i] != '$')
	{
		new[i] = arg[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	check_golfje(char *arg)
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

bool	ft_prev_arg(char *arg, int i)
{
	while (arg[i])
	{
		ft_putstr_fd(&arg[i], 1);
		i++;
	}
	return (true);
}

bool	ft_next_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] != '-')
	{
		return (true);
	}
	while (arg[i])
	{
		if (arg[i] != 'n')
		{
			return (true);
		}
		i++;
	}
	return (false);
}

bool	ft_newline(char *args, bool yeet)
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

int	builtin_echo(int argc, char **args)
{
	int		i;
	bool	newline;
	bool	yeet;

	newline = true;
	yeet = true;
	i = 1;
	if (!check_argcount(argc))
		return (0);
	while (args[i])
	{
		if (ft_newline(args[i], yeet))
			newline = false;
		if (!echo_exit(args[i]) && !check_golfje(args[i]) \
			&& !check_arg_env(args[i]) && !ft_newline(args[i], yeet))
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1])
				ft_putchar_fd(' ', 1);
		}
		i++;
	}
	if (newline)
		ft_putchar_fd('\n', 1);
	return (1);
}
