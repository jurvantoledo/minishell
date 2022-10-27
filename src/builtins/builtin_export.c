/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_export.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 14:14:09 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/27 15:32:57 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	print_env(void)
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
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(env->value, 1);
			ft_putchar_fd('"', 1);
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


void	builtin_export(int argc, char **args)
{
	int	i;

	if (argc == 1)
	{
		print_env();
		return ;
	}
	i = 0;
	while (args[i + 1])
	{
		i++;
		if (ft_strchr(args[i], '=') == NULL)
		{
			if (!handle_no_val(args[i]))
				return ;
			else
				continue ;
		}
		else
			if (!add_env_var(&g_shell.env, args[i]))
				return ;
	}
}
