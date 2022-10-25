/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 15:29:07 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/24 18:16:30 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int set_env_key(t_env *env, char *env_str)
{
	size_t len1;
	size_t len2;

	len1 = 0;
	len2 = 0;
	while (env_str[len1] != '=')
		len1++;
	while (env_str[len1 + len2 + 1])
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
	ft_memcpy(env->key, env_str, (len1 + 1));
	ft_memcpy(env->value, (env_str + len1 + 1), len2);
	return (1);
}

static int add_to_env(t_env **head, char *envp)
{
	t_env *tmp;
	t_env *new;

	new = ft_calloc(sizeof(t_env), 1);
	if (!new)
		return (0);
	if (!set_env_key(new, envp))
		return (0);
	if (*head == NULL)
	{
		*head = new;
		return (1);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (1);
}

t_env *parse_env(char *envp[])
{
	t_env *head;

	head = NULL;
	if (!envp)
		return (NULL);
	while (*envp)
	{
		if (!add_to_env(&head, *envp))
			return (clear_env(head));
		envp++;
	}
	printf("%s\n", head->key);
	return (head);
}

t_env *get_env(t_env *head, char *pathname)
{
	while (head)
	{
		if (ft_strlen(head->key) == ft_strlen(pathname) && ft_strncmp(head->key, pathname, ft_strlen(head->key)) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}

char **set_env(void)
{
	char **res;
	char **temp;
	t_env *env;
	int i;

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
