/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_extra.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/23 16:05:22 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/07 14:17:38 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*key_val(char *str)
{
	t_env	*env;
	char	*key;
	int		i;

	key = ft_calloc(sizeof(char *), 1);
	if (!key)
		return (0);
	i = 0;
	while (str[i] != '=')
	{
		key[i - 1] = str[i];
		i++;
	}
	key[i] = '\0';
	env = get_env(g_shell.env, key);
	if (!env)
		return (NULL);
	return (env->value);
}

char	*str_val(char *str)
{
	char	*val;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '=')
		i++;
	val = ft_calloc(sizeof(char *), 1);
	if (!val)
		return (0);
	j = 0;
	while (str[i + j])
	{
		val[j] = str[i + j];
		j++;
	}
	val[j] = '\0';
	return (val);
}

char	*check_new_env_var(char *str)
{
	char	*key;
	char	*val;
	char	*new_str;

	if (ft_strncmp(str, "$", 1) == 0)
	{
		key = key_val(str);
		val = str_val(str);
		new_str = ft_strjoin(key, val);
		if (!new_str)
			return (NULL);
		free(key);
		free(val);
		return (new_str);
	}
	return (str);
}
