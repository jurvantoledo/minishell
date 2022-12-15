/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shlvl.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 10:13:37 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/15 15:52:06 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	init_shlvl(void)
{
	char	*convert;

	convert = ft_itoa(1);
	if (!convert)
	{
		free(convert);
		return (false);
	}
	return (true);
}

int	set_shlvl(void)
{
	t_env	*sh;
	int		shlvl;
	char	*sheesh;

	sh = get_env(g_shell.env, "SHLVL");
	if (!sh)
		return (init_shlvl());
	shlvl = ft_atoi(sh->value) + 1;
	sheesh = ft_itoa(shlvl);
	if (!sheesh)
	{
		free(sheesh);
		return (0);
	}
	if (!update_env(g_shell.env, sh->key, sheesh))
	{
		free(sheesh);
		return (0);
	}
	return (1);
}
