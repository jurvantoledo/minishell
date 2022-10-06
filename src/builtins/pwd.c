/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:30:54 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/06 14:08:03 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	pwd(void)
{
	t_env	*pwd;

	pwd = get_env(g_shell.env, "PWD");
	if (ft_strncmp(pwd->key, "PWD", 3) == 0)
	{
		ft_putendl_fd(pwd->value, 1);
		return (1);
	}
	return (0);
}
