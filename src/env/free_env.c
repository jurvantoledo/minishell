/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_env.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 17:50:47 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/24 18:08:18 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env *clear_env(t_env *env)
{
	t_env *temp;

	while (env)
	{
		temp = env->next;
		free(env->key);
		free(env->value);
		free(env);
		env = temp;
	}
	return (NULL);
}
