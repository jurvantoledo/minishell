/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:39:42 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/09/09 10:59:09 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"

# define MINISHELL_H
# define SPECIAL_CHAR "$|<>\'\""

typedef enum e_token_type {
	INFILE,
	OUTFILE,
	OUTFILE_APPEND,
	HERE_DOC,
	ARGUMENT,
	COMMAND,
	PIPE,
}	t_token_type;

typedef struct s_env {
	int				key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_token {
	t_token_type	*type;
}	t_token;

// Envp parser for storing the keys and values of envp
void	parse_env(char *envp[]);

// The lexer
void	ft_snorlexer(char *input);

#endif
