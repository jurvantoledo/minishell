/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_echo_utils.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 17:36:01 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/25 15:40:02 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	handle_arg_env(char *arg)
{
	t_env	*env;
	int		i;
	int		j;
	char	*new_arg;

	i = 0;
	if (arg[i] == '$')
	{
		i++;
		new_arg = get_env_arg(&arg[i]);
		env = get_env(g_shell.env, new_arg);
		if (!env)
		{
			j = 0;
			while (ft_iscapital(new_arg[j]))
				j++;
			new_arg[j] = '\0';
			env = get_env(g_shell.env, new_arg);
			if (!env)
				return (0);
		}
		ft_putstr_fd(env->value, STDOUT_FILENO);
	}
	return (1);
}

int	check_arg_env(char *arg)
{
	t_env	*env;
	int		i;
	int		j;
	char	*new_arg;

	i = 0;
	if (ft_strncmp(arg, "$", 1) == 0)
	{
		while (arg[i])
		{
			if (!handle_arg_env(&arg[i]))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
