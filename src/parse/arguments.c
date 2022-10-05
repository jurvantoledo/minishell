/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arguments.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 15:18:34 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/05 14:43:29 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Check for arguments $ if $? return last exit_code
static int	arg_len(char *input)
{
	int	i;

	i = 1;
	while ((input[i] && special_chars(input[i]) == 0) && !ft_isspace(input[i]))
		i++;
	return (i - 1);
}

int	check_args(char *input, t_lexer *lexer)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (input[i])
	{
		if (input[i] == '$' && input[i + 1] == '?')
			return (g_shell.exit_code);
		else if (input[i] == '$')
		{
			len = arg_len(&input[i]);
			return (1);
		}
		i++;
		len = 0;
	}
	return (0);
}
