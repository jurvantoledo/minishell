/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:38:46 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/05 16:56:04 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_shell	g_shell;

int	clean_shell(t_lexer *lexer, int exit, bool exit_prog)
{
	int	i;
	int	j;

	if (exit_prog)
		clear_list(&g_shell.env);
	i = 0;
	while ((size_t)i < g_shell.cmd_len)
	{
		j = 0;
		if (g_shell.command[i].fd_in > 2)
			close(g_shell.command[i].fd_in);
		if (g_shell.command[i].fd_out > 2)
			close(g_shell.command[i].fd_out);
		while (g_shell.command[i].arguments && g_shell.command[i].arguments[j])
		{
			free(g_shell.command[i].arguments[j]);
			j++;
		}
		free(g_shell.command[i].arguments);
		free(g_shell.command[i].path);
		i++;
	}
	free(g_shell.command);
	g_shell.command = NULL;
	g_shell.cmd_len = 0;
	clear_token_list(&lexer);
	lexer = NULL;
	return (exit);
}

int	ft_run_shell(char *input)
{
	g_shell.lexer = ft_snorlexer(input);
	if (!g_shell.lexer)
	{
		clean_shell(g_shell.lexer, 0, true);
		free(input);
		return (1);
	}
	if (!ft_paraser(input, g_shell.lexer) || !resolve_path() \
		|| !ft_exeggutor())
	{
		free(input);
		exit(clean_shell(g_shell.lexer, EXIT_FAILURE, true));
	}
	add_history(input);
	clean_shell(g_shell.lexer, 0, false);
	free(input);
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*input;

	rl_catch_signals = 0;
	(void)argc;
	(void)argv;
	g_shell.env = parse_env(envp);
	if (!g_shell.env)
		exit(EXIT_FAILURE);
	if (!set_shlvl())
		exit(EXIT_FAILURE);
	while (1)
	{
		init_signal();
		input = readline("[terminal cancer]: ");
		if (!input)
		{
			ft_putendl_fd("exit", 1);
			exit(clean_shell(NULL, 1, true));
		}
		ft_run_shell(input);
		// system("leaks minishell");
	}
	return (0);
}
