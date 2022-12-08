/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_echo_utils.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 17:36:01 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/08 14:59:40 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*expand_lol_dollar(char *input)
{
	t_env	*env;
	char	*new_input;
	int		i;

	while (input[i])
	{
		if (input[i] == '$')
		{
			i++;
			new_input = get_env_arg(&input[i]);
			env = get_env(g_shell.env, new_input);
			if (!env)
			{
				// ft_putstr_fd("", STDOUT_FILENO);
				return (0);
			}
			return (env->value);
		}
		i++;
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (input);
}

static int	handle_arg_env(char *arg)
{
	t_env	*env;
	int		i;
	char	*new_arg;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '$')
		{
			i++;
			new_arg = get_env_arg(&arg[i]);
			if (!new_arg)
				return (0);
			env = get_env(g_shell.env, new_arg);
			if (!env)
				return (0);
			ft_putstr_fd(env->value, STDOUT_FILENO);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_arg_env(char *arg)
{
	// printf("the arg: %s\n", arg);
	// if (!handle_arg_env(arg))
	// 	return (0);
	ft_putstr_fd(arg, STDOUT_FILENO);
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
