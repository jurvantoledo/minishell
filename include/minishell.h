/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:39:42 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/09/23 12:16:22 by jvan-tol      ########   odam.nl         */
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
	PIPE,
	COMMAND,
}	t_token_type;

typedef struct s_env {
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_lexer {
	t_token_type	type;
	char			*arg;
	int				length;
	int				index;
	struct s_lexer	*next;
}	t_lexer;

// Envp parser for storing the keys and values of envp
void	parse_env(char *envp[]);

// Lexer Functions
void	ft_snorlexer(char *input);
int		check_quotes(char *input);
void	post_processing(char *input, t_lexer *lexer);

// Util Functions
int		special_chars(char c);
void	update_data(t_lexer *head, int old, int new);

// List Functions
void	print_list(t_lexer *head);

#endif
