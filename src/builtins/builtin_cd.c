/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_cd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 12:50:41 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/01 11:40:18 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* 
	--------------> getcwd() <----------------
	Determines the path name of the working directory and stores it in buffer.
*/

static int	set_pwd(char *old)
{
	char	cwd[MAX_PATH];

	getcwd(cwd, sizeof(cwd));
	if (!update_env(g_shell.env, "PWD", ft_strdup(cwd)))
		return (0);
	if (!update_env(g_shell.env, "OLDPWD", ft_strdup(old)))
		return (0);
	return (1);
}

static int	set_path(char *path)
{
	char	cwd[MAX_PATH];

	getcwd(cwd, sizeof(cwd));
	if (!path || chdir(path) < 0)
		return (0);
	if (!set_pwd(cwd))
		return (0);
	return (1);
}

int	set_cd(int argc, char *path)
{
	t_env	*dir;
	char	cwd[MAX_PATH];

	if (ft_strncmp(path, "~", 2) == 0)
	{
		dir = get_env(g_shell.env, "HOME");
		if (!dir)
			return (0);
		if (!set_path(dir->value))
			return (0);
	}
	if (!set_path(path))
		return (0);
	return (1);
}

int	builtin_cd(int argc, char **argv)
{
	t_env	*dir;

	if (argc > 2)
	{
		ft_putendl_fd("Too many arguments", 1);
		return (0);
	}
	else if (argc > 1)
	{
		set_cd(argc, argv[1]);
		return (1);
	}
	else if (argc == 1)
	{
		dir = get_env(g_shell.env, "HOME");
		if (!dir)
			return (0);
		if (!set_path(dir->value))
			return (0);
	}
	return (0);
}
