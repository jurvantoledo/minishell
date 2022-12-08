/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cmds_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 11:44:00 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/08 15:56:51 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	what_am_i_doing(char *val)
{
	char	**loc;
	char	*path;

	if (access(val, F_OK & X_OK) == -1)
	{
		loc = ft_split(val, ' ');
		if (!loc)
			return (false);
		path = parse_path(loc[0]);
		if (check_builtin(loc[0]) || path != NULL)
		{
			free(path);
			ft_free_char(loc);
			return (true);
		}
		ft_free_char(loc);
		return (false);
	}
	return (false);
}

bool	maybe_expand_adjacent(char *str)
{
	int		i;
	t_env	*env;
	char	**loc;
	char	*path;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			env = get_env(g_shell.env, &str[i]);
			if (!env)
				return (false);
			return (what_am_i_doing(env->value));
		}
		i++;
	}
	return (false);
}

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
