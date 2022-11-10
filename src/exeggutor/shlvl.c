/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shlvl.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 10:13:37 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/10 12:14:43 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	set_shlvl(void)
{
	t_env	*sh;
	int		shlvl;
	char	*sheesh;

	sh = get_env(g_shell.env, "SHLVL");
	if (!sh)
	{
		sheesh = ft_itoa(1);
		return (0);
	}
	shlvl = ft_atoi(sh->value) + 1;
	sheesh = ft_itoa(shlvl);
	if (!update_env(g_shell.env, sh->key, sheesh))
		return (0);
	return (1);
}
