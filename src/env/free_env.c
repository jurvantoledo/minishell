/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_env.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 17:50:47 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/26 16:24:01 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env	*clear_list(t_env **head)
{
	t_env	*thead;
	t_env	*tmp;

	thead = *head;
	while (thead)
	{
		tmp = thead->next;
		free(thead->key);
		free(thead->value);
		free(thead);
		thead = tmp;
	}
	*head = NULL;
	return (NULL);
}

int	remove_node(t_env **head, char *key)
{
	t_env	*tmp;
	t_env	*env;

	env = get_env(*head, key);
	if (!env)
		return (0);
	if (*head == env)
	{
		*head = (*head)->next;
		free(env->key);
		free(env->value);
		free(env);
		return (1);
	}
	tmp = *head;
	while (tmp->next != env)
		tmp = tmp->next;
	tmp->next = tmp->next->next;
	free(env->key);
	free(env->value);
	free(env);
	return (1);
}
