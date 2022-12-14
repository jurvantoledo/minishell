/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_pwd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:30:54 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/08 13:24:13 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	print_old_pwd(void)
{
	t_env	*pwd;
	t_env	*new_pwd;

	pwd = get_env(g_shell.env, "OLDPWD");
	if (!pwd)
		return (0);
	if (ft_strncmp(pwd->key, "OLDPWD", 7) == 0)
	{
		new_pwd = get_env(g_shell.env, "PWD");
		ft_putendl_fd(new_pwd->value, 1);
		return (1);
	}
	return (0);
}

int	builtin_pwd(void)
{
	char	*pwd;
	t_env	*env_pwd;

	env_pwd = get_env(g_shell.env, "PWD");
	if (env_pwd)
	{
		ft_putendl_fd(env_pwd->value, 1);
		return (0);
	}
	pwd = getenv("PWD");
	if (!pwd)
		return (1);
	ft_putendl_fd(pwd, 1);
	return (0);
}
