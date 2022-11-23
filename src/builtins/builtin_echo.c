/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_echo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 10:41:17 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/23 17:23:19 by jvan-tol      ########   odam.nl         */
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

int	check_arg_env(char *arg)
{
	t_env	*env;
	char	**split_arg;
	int		i;

	i = 0;
	split_arg = ft_split(arg, '$');
	if (!split_arg)
		return (0);
	while (split_arg[i])
	{
		env = get_env(g_shell.env, split_arg[i]);
		if (!env)
			return (0);
		ft_putstr_fd(env->value, STDOUT_FILENO);
		i++;
	}
	return (1);
}

int	check_golfje(char *arg)
{
	t_env	*dir;
	int		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '~')
		{
			dir = get_env(g_shell.env, "HOME");
			if (!dir)
				return (0);
			ft_putstr_fd(dir->value, 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	builtin_echo(int argc, char **args)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	if (!check_argcount(argc))
		return (0);
	if (ft_strncmp(args[1], "-n", 3) == 0)
	{
		newline = 0;
		i = 2;
	}
	while (args[i])
	{
		if (echo_exit(args[i]) == 1 && \
		check_golfje(args[i]) == 1)
			return (1);
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (newline == 1)
		ft_putchar_fd('\n', 1);
	return (1);
}
