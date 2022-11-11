/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_cd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 12:50:41 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/11 12:43:31 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

int	set_path(char *path)
{
	char	cwd[MAX_PATH];

	getcwd(cwd, sizeof(cwd));
	printf("het pad: %s\n", path);
	if ((!path || chdir(path) < 0))
	{
		return (errors("minishell", path, "No such file or directory", 1));
	}
	if (!set_pwd(cwd))
		return (0);
	return (1);
}

int	cd_flags(char *path)
{
	t_env	*dir;

	if (ft_strncmp(path, "~", 2) == 0 && ft_strlen(path) == 1)
	{
		dir = get_env(g_shell.env, "HOME");
		if (!dir)
			return (0);
		if (!set_path(dir->value))
			return (0);
	}
	else if (ft_strncmp(path, "-", 2) == 0 && ft_strlen(path) == 1)
	{
		if (!set_old_cd(path))
			return (0);
	}
	return (1);
}

int	set_cd(int argc, char *path)
{
	char	*new_path;
	char	cwd[MAX_PATH];
	t_env	*dir;

	if (ft_strncmp(path, "~", 2) == 0 || ft_strncmp(path, "-", 2) == 0)
	{
		if (!cd_flags(path))
			return (0);
	}
	else if (ft_strncmp(path, "~/", 2) == 0 && ft_strlen(path) != 1)
	{
		dir = get_env(g_shell.env, "HOME");
		if (!dir)
			return (0);
		if (!cd_home_path(dir, path))
			return (0);
	}
	else
	{
		if (!set_path(path))
			return (0);
	}
	return (1);
}

int	builtin_cd(int argc, char **argv)
{
	t_env	*dir;
	char	cwd[MAX_PATH];

	if (argc > 2)
	{
		ft_putendl_fd("Too many arguments", 1);
		return (0);
	}
	else if (argc > 1)
	{
		if (!set_cd(argc, argv[1]))
			return (0);
	}
	else if (argc == 1)
	{
		dir = get_env(g_shell.env, "HOME");
		if (!dir)
			return (0);
		if (!set_path(dir->value))
			return (0);
	}
	return (1);
}
