/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:35:26 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/01 14:06:29 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sig_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		printf("hallo\n");
		rl_replace_line("", 0);
		printf("hallo2\n");
		rl_redisplay();
	}
}

void	signals(void)
{
	struct sigaction	sig;

	sig.sa_handler = &sig_handler;
	sigaction(SIGINT, &sig, NULL);
	sigaction(SIGQUIT, &sig, NULL);
}
