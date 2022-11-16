/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 11:58:24 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/16 14:26:50 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	expand_dollar(char *input)
{
	t_env	*env;
	int		i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '$')
		{
			i++;
			env = get_env(g_shell.env, &input[i]);
			if (!env)
				return (0);
			ft_putendl_fd(env->value, 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	expander(char *input)
{
	if (expand_dollar(input) == 1)
		return (1);
	return (0);
}
