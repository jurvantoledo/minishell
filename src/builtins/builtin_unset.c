/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_unset.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:38:42 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/24 15:14:08 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	unset_env(t_env **head_ref, char *key)
{
	t_env	*temp;

	temp = *head_ref;
	printf("temp: %s  key: %s\n", temp->key, key);
	if (temp != NULL && ft_strncmp(temp->key, key, ft_strlen(key)) == 0)
	{
		*head_ref = temp->next;
		free(temp->key);
		free(temp->value);
		free(temp);
		return ;
	}
	while (temp && (ft_strncmp(temp->key, key, ft_strlen(key)) != 0))
	{
		*head_ref = temp->next;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	(*head_ref)->next = temp->next;
	free(temp->key);
	free(temp->value);
	free(temp);
}

int	builtin_unset(int argc, char **args)
{
	char	*key;
	int		i;

	if (!g_shell.env)
		return (0);
	i = 1;
	while (args[i])
	{
		remove_node(&g_shell.env, args[i]);
		i++;
	}
	return (1);
}
