/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 11:58:24 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/05 16:55:34 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	expand_adjacent(char *input)
{
	char	**loc;
	t_lexer	*lexer;

	lexer = NULL;
	loc = ft_split(input, ' ');
	if (!loc)
		return (NULL);
	if (check_builtin(loc[0]) || parse_path(loc[0]) != NULL)
	{
		lexer = ft_snorlexer(input);
		if (!lexer)
		{
			clean_shell(lexer, 0, false);
			free(input);
			return (false);
		}
		if (!ft_paraser(input, lexer) || !resolve_path() \
			|| !ft_exeggutor())
		{
			free(input);
			exit(clean_shell(lexer, EXIT_FAILURE, true));
		}
		clean_shell(lexer, 0, false);
		ft_free_char(loc);
		return (true);
	}
	ft_free_char(loc);
	return (false);
}

bool	expand_value(char *value)
{
	return (expand_adjacent(value));
}

int	expand_dollar(char *input)
{
	t_env	*env;
	int		i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '$')
		{
			i++;
			env = get_env(g_shell.env, &input[i]);
			if (!env)
				return (0);
			if (expand_value(env->value))
				return (1);
			else
			{				
				ft_putendl_fd(env->value, 1);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	expander(char *input)
{
	if (expand_dollar(input) == 1)
		return (1);
	return (0);
}
