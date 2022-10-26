/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 12:14:11 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/26 16:54:32 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

size_t	env_len(void)
{
	size_t	len;
	t_env	*env;

	len = 0;
	env = g_shell.env;
	while (env)
	{
		len++;
		env = env->next;
	}
	return (len);
}

int	strenv(char **res, t_env *env)
{
	res[0] = env->key;
	if (!res[0])
	{
		free(res);
		return (0);
	}
	res[0] = ft_strjoin(res[0], "=");
	if (!res[0])
	{
		free(res);
		return (0);
	}
	res[0] = ft_strjoin(res[0], env->value);
	if (!res[0])
	{
		free(res);
		return (0);
	}
	return (1);
}

// Sorteer de lijst head = TMPDIR
void	sort_env(t_env **head)
{
	// t_env	*env;
	// t_env	*tmp;

	// env = *head;
	// while (env && env->next)
	// {
	// 	if (ft_strcmp(env->key, env->next->key) > 0)
	// 	{
	// 		tmp = env;
	// 		env = env->next;
	// 		env->next = tmp;
	// 	}
	// 	env = env->next;
	// }
	return ;
}
