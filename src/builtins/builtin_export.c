/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_export.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 14:14:09 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/21 16:25:25 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	print_env_value(char *value)
{
	if (check_val_quotes(value) == 0)
	{
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(value, 1);
		ft_putchar_fd('"', 1);
	}
	else
	{
		ft_putstr_fd("=", 1);
		ft_putstr_fd(value, 1);
	}
}

static int	check_env(void)
{
	t_env	*env;

	env = g_shell.env;
	if (!env)
		return (0);
	while (env)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(env->key, 1);
		if (env->value)
		{
			print_env_value(env->value);
		}
		ft_putchar_fd('\n', 1);
		env = env->next;
	}
	return (1);
}

static	int	handle_no_val(char *str)
{
	t_env	*env;

	if (get_env(g_shell.env, str))
		return (1);
	env = ft_calloc(1, sizeof(t_env));
	if (!env)
		return (0);
	env->key = ft_strdup(str);
	if (!env->key)
	{
		free(env);
		return (0);
	}
	sort_env(&g_shell.env, env);
	return (1);
}

int	builtin_export(int argc, char **args)
{
	int	i;

	if (argc == 1)
	{
		check_env();
		return (1);
	}
	i = 0;
	while (args[i + 1])
	{
		i++;
		if (!args_identifier(args[i]))
			return (1);
		if (ft_strchr(args[i], '=') == NULL)
		{
			if (!handle_no_val(args[i]))
				return (1);
			else
				continue ;
		}
		if (!add_env_var(&g_shell.env, args[i]))
			return (1);
	}
	return (0);
}
