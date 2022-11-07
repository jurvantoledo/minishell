/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_cd_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 15:29:56 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/07 15:32:42 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cd_home_path(t_env *dir, char *path)
{
	char	*new;
	int		i;

	if (!path)
		return (0);
	i = 0;
	while (path[i])
	{
		if (path[i] == '~')
		{
			i++;
			new = ft_strjoin(dir->value, &path[i]);
			if (!new)
				return (0);
			if (!set_path(new))
				return (0);
		}
		i++;
	}
	return (1);
}

int	set_old_cd(char *path)
{
	t_env	*dir;

	dir = get_env(g_shell.env, "OLDPWD");
	if (!dir)
		return (0);
	if (!set_path(dir->value))
		return (0);
	print_old_pwd();
	return (1);
}
