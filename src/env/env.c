/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 15:29:07 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/05 15:05:45 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env	*parse_env(char *envp[])
{
	t_env	*head;
	t_env	*type;
	int		i;
	char	**split_envp;

	type = ft_calloc(sizeof(t_env), 1);
	if (!type)
		return (NULL);
	head = type;
	i = 0;
	while (envp[i])
	{
		split_envp = ft_split(envp[i], '=');
		if (!split_envp)
			return (NULL);
		type->key = split_envp[0];
		type->value = split_envp[1];
		if (type->value && type->key)
		{
			type->next = ft_calloc(sizeof(t_env), 1);
			type = type->next;
		}
		i++;
	}
	return (head);
}

void	get_env(t_env *head, char *pathname)
{

}
