/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 15:29:07 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/21 18:06:39 by jvan-tol      ########   odam.nl         */
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

t_env	*get_env(t_env *head, char *pathname)
{
	while (head)
	{
		if (ft_strlen(head->key) == ft_strlen(pathname) \
			&& ft_strncmp(head->key, pathname, ft_strlen(head->key)) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}

unsigned int	env_len(void)
{
	unsigned int	len;
	t_env			*env;

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
		return (0);
	res[0] = ft_strjoin(res[0], "=");
	if (!res[0])
		return (0);
	res[0] = ft_strjoin(res[0], env->value);
	if (!res[0])
		return (0);
	return (1);
}

char	**set_env(void)
{
	char			**res;
	char			**temp;
	t_env			*env;
	int				i;

	res = ft_calloc(sizeof(char *), env_len() + 1);
	env = g_shell.env;
	i = 0;
	while (env)
	{
		if (!strenv(&res[i], env))
		{
			ft_free_char(res);
			return (NULL);
		}
		env = env->next;
		i++;
	}
	return (res);
}
