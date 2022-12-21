/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 15:29:07 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/21 16:39:33 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	add_str_env(t_env *env, char *str)
{
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	while (str[len1] != '=')
		len1++;
	while (str[len1 + len2 + 1])
		len2++;
	env->key = ft_calloc(sizeof(char), len1 + 1);
	env->value = ft_calloc(sizeof(char), len2 + 1);
	if (!env->key || !env->value)
	{
		free(env->key);
		free(env->value);
		free(env);
		return (0);
	}
	ft_memcpy(env->key, str, len1);
	ft_memcpy(env->value, &str[len1 + 1], len2);
	return (1);
}

int	add_env(t_env **head, char *env)
{
	t_env	*new;

	new = ft_calloc(sizeof(t_env), 1);
	if (!new)
		return (0);
	if (!add_str_env(new, env))
		return (0);
	if (*head == NULL)
	{
		*head = new;
		return (1);
	}
	sort_env(head, new);
	return (1);
}

t_env	*parse_env(char *envp[])
{
	t_env	*head;

	head = NULL;
	if (!envp)
		return (NULL);
	while (*envp)
	{
		if (!add_env(&head, *envp))
			return (clear_list(&head));
		envp++;
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

char	**set_env(void)
{
	char			**res;
	t_env			*env;
	int				i;

	res = ft_calloc(sizeof(char *), env_len() + 1);
	if (!res)
		return (NULL);
	env = g_shell.env;
	if (!env)
		return (NULL);
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
