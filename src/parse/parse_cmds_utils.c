/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cmds_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 11:44:00 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/21 16:47:35 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**new_args(char *str)
{
	int		i;
	t_env	*env;
	char	**loc;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			env = get_env(g_shell.env, &str[i]);
			if (!env)
				return (NULL);
			loc = ft_split(env->value, ' ');
			if (!loc)
				return (NULL);
			return (loc);
		}
		i++;
	}
	return (NULL);
}

char	**adjacent_args(char **args, char *str)
{
	free(args);
	args = new_args(str);
	free(str);
	return (args);
}
