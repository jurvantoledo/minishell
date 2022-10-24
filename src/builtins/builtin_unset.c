/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_unset.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:38:42 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/24 18:18:01 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	builtin_unset(void)
{
	t_env	*env;
	char	*key;
	int		i;

	env = g_shell.env;
	if (!env)
		return (0);
	i = 0;
	while (env->next)
	{
		key = g_shell.command[0].arguments[1];
		if (ft_strncmp(env->key, key, ft_strlen(env->key)) == 0)
		{
			clear_list(env);
		}
		env = env->next;
	}
}
