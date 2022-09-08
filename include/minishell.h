/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:39:42 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/09/08 16:45:03 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"

# define MINISHELL_H

typedef enum e_token_type {
	INFILE,
	OUFILE,
	OUTFILE_APPEND,
	HERE_DOC,
	ARGUMENT,
	COMMAND,
	PIPE,
}	t_token_type;

typedef struct s_env_parsed {
	int						key;
	char					*value;
	struct s_env_parsed	*next;
}	t_env_parsed;

// Envp parser for storing the keys and values of envp
void	parse_env(char *envp[]);

// The lexer
void	ft_snorlexer(int argc, char *argv[], char *envp[]);

#endif
