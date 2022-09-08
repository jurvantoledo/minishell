/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_parser.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 15:29:07 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/09/08 17:36:06 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parse_env(char *envp[])
{
	t_env_parsed	*head;
	t_env_parsed	*type;
	int				i;
	char			**split_envp;

	type = ft_calloc(sizeof(t_env_parsed), 1);
	if (!type)
		return ;
	head = type;
	i = 0;
	while (envp[i])
	{
		split_envp = ft_split(envp[i], '=');
		type->key = i;
		type->value = split_envp[1];
		if (type->value && type->key)
		{
			type->next = ft_calloc(sizeof(t_env_parsed), 1);
			type = type->next;
		}
		i++;
	}
}
