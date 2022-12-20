/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 12:14:11 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/20 14:42:18 by jvan-tol      ########   odam.nl         */
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
		ft_free_char(res);
		return (0);
	}
	res[0] = ft_strjoin(res[0], "=");
	if (!res[0])
	{
		ft_free_char(res);
		return (0);
	}
	if (env->value)
	{
		res[0] = ft_strjoin(res[0], env->value);
		if (!res[0])
		{
			ft_free_char(res);
			return (0);
		}
	}
	return (1);
}

int	add_env_var(t_env **head, char *var_str)
{
	t_env	*new;

	new = ft_calloc(sizeof(t_env), 1);
	if (!new)
		return (0);
	if (!add_str_env(new, var_str))
		return (0);
	if (*head == NULL)
	{
		*head = new;
		return (1);
	}
	sort_env(head, new);
	return (1);
}

void	sort_env(t_env **head, t_env *new)
{
	t_env	*tmp;

	if (get_env(g_shell.env, new->key))
		remove_node(&g_shell.env, new->key);
	if (ft_strcmp((*head)->key, new->key) > 0)
	{
		new->next = (*head);
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next && ft_strcmp(tmp->next->key, new->key) < 0)
		tmp = tmp->next;
	new->next = tmp->next;
	tmp->next = new;
}

int	update_env(t_env *head, char *val, char *new_val)
{
	head = get_env(g_shell.env, val);
	if (!head)
		return (0);
	else if (head)
	{
		free(head->value);
		head->value = new_val;
		return (1);
	}
	free(new_val);
	return (1);
}
