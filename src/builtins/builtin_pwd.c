/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_pwd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:30:54 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/04 11:43:08 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	print_old_pwd(void)
{
	t_env	*pwd;
	t_env	*new_pwd;
	int		i;

	pwd = get_env(g_shell.env, "OLDPWD");
	if (!pwd)
		return (0);
	i = 0;
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
	t_env	*pwd;

	pwd = get_env(g_shell.env, "PWD");
	if (!pwd)
		return (0);
	if (ft_strncmp(pwd->key, "PWD", ft_strlen(pwd->key)) == 0)
	{
		ft_putendl_fd(pwd->value, 1);
		return (1);
	}
	return (0);
}
