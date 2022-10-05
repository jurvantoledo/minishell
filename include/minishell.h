/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:39:42 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/05 12:34:30 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"

# define MINISHELL_H
# define SPECIAL_CHAR "$|<>\"\'"

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

typedef struct s_infile {
	char			*infile;
	char			*heredick;
	struct s_infile	*next;
}	t_infile;

typedef struct s_outfile
{
	char				*outfile;
	char				*out_append;
	struct s_outfile	*next;
}	t_outfile;

typedef struct s_lexer {
	t_token_type		type;
	int					length;
	int					index;
	struct s_infile		*in;
	struct s_outfile	*out;
	struct s_lexer		*next;
}	t_lexer;

typedef struct s_shell
{
	t_env	*env;
	int		exit_code;
	int		fd_in;
	int		fd_out;
	int		pipe[2];
	pid_t	pid;
	t_lexer	*lexer;
}	t_shell;

extern t_shell	g_shell;

// Envp parser for storing the keys and values of envp
t_env	*parse_env(char *envp[]);

// Lexer Functions
t_lexer	*ft_snorlexer(char *input);
int		check_quotes(char *input);

// Parser
void	ft_parser(char *input, t_lexer *lexer);
int		check_files(char *input, t_lexer *lexer, t_infile *in, t_outfile *out);
void	check_args(char *input, t_lexer *lexer);

// Util Functions
int		special_chars(char c);
void	print_list(t_lexer *head);
void	print_file_list(t_infile *in_head, t_outfile *out_head);

#endif
