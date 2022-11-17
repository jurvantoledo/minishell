/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/23 14:41:24 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/17 12:44:12 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_paraser(char *input, t_lexer *lexer)
{
	if (!lexer)
		return (0);
	if (!parse_files(input, lexer))
		return (0);
	parse_cmds(input, lexer);
	return (1);
}
