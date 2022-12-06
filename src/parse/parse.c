/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 14:41:24 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/06 15:37:43 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// char	*expanded_arg(char *input, t_lexer *lexer, int j)
// {
// 	char	**loc;
// 	t_env	*env;

// 	env = get_env(g_shell.env, input);
// 	if (!env)
// 		return (NULL);
// 	loc = ft_split(env->value, ' ');
// 	if (!loc)
// 		return (NULL);
// 	while (loc[j])
// 	{
// 		j++;
// 		return (loc[j]);
// 	}
// }

// char	*expand(char *input, t_lexer *lexer)
// {
// 	char	**loc;
// 	t_env	*env;
// 	int		i;
// 	int		j;
// 	char	*cmd;

// 	i = 0;
// 	while (input[i])
// 	{
// 		j = -1;
// 		if (input[i] == '$')
// 		{
// 			i++;
// 			cmd = expanded_arg(&input[i], lexer, j);
// 			printf("cmd after expanded arg: %s\n", cmd);
// 		}
// 		i++;
// 	}
// 	return (input);
// }

int	ft_paraser(char *input, t_lexer *lexer)
{
	if (!lexer)
		return (0);
	if (!parse_cmds(input, lexer))
		return (0);
	if (!parse_files(input, lexer))
		return (0);
	return (1);
}
