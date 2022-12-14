/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:38:46 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/14 13:09:58 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_shell	g_shell;

int	clean_shell(t_lexer *lexer, int exit, bool exit_prog)
{
	if (exit_prog)
		clear_list(&g_shell.env);
	purge_commands();
	clear_token_list(&lexer);
	lexer = NULL;
	return (exit);
}

static int	ft_run_shell(char *input)
{
	char	*expand_inp;

	input = expand_dollar(input);
	g_shell.lexer = ft_snorlexer(input);
	if (!g_shell.lexer)
	{
		clean_shell(g_shell.lexer, 0, false);
		free(input);
		return (1);
	}
	if (!ft_paraser(input, g_shell.lexer) || !resolve_path() \
		|| !ft_exeggutor())
	{
		free(input);
		exit(clean_shell(g_shell.lexer, EXIT_FAILURE, true));
	}
	clean_shell(g_shell.lexer, 0, false);
	free(input);
	return (1);
}

char	*read_command_line(void)
{
	char	*input;

	input = readline("[terminal cancer]: ");
	if (!input)
	{
		ft_putendl_fd("exit", 1);
		rl_clear_history();
		exit(clean_shell(NULL, g_shell.exit_code, true));
	}
	if (input && *input)
		add_history(input);
	return (input);
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
		exit(clean_shell(NULL, EXIT_FAILURE, true));
	while (1)
	{
		init_signal();
		input = read_command_line();
		ft_run_shell(input);
	}
	return (0);
}
