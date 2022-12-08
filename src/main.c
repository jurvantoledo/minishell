/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:38:46 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/08 12:58:24 by jvan-tol      ########   odam.nl         */
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

static char	*sanitize(char *inp)
{
	int	index;

	if (!inp)
		return (NULL);
	index = 0;
	while (inp[index])
		index++;
	index--;
	while (index >= 0)
	{
		if (!ft_strchr("\t ", inp[index]))
			break ;
		inp[index] = '\0';
		index--;
	}
	if (!inp)
	{
		free(inp);
		return (NULL);
	}
	return (inp);
}

static int	ft_run_shell(char *input)
{
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
		exit(clean_shell(NULL, EXIT_FAILURE, true));
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
	}
	return (0);
}
