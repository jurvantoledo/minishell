/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:39:42 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/10/21 12:16:14 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
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

typedef struct s_files
{
	t_infile			*in;
	t_outfile			*out;
}	t_files;

typedef struct s_command {
	char				*path;
	char				**arguments;
}	t_command;

typedef struct s_lexer {
	t_token_type		type;
	int					length;
	int					index;
	t_infile			*in;
	t_outfile			*out;
	struct s_lexer		*next;
}	t_lexer;

typedef struct s_shell
{
	t_env		*env;
	int			exit_code;
	int			fd_in;
	int			fd_out;
	int			pipe[2];
	size_t		cmd_len;
	pid_t		pid;
	t_lexer		*lexer;
	t_files		*files;
	t_command	*command;
}	t_shell;

extern t_shell	g_shell;

int		main(int argc, char *argv[], char *envp[]);

// Envp parser for storing the keys and values of envp
t_env	*parse_env(char *envp[]);
t_env	*get_env(t_env *head, char *pathname);
char	**set_env(void);

// Lexer Functions
t_lexer	*ft_snorlexer(char *input);
int		check_quotes(char *input);
void	post_process(char *input, t_lexer *lexer);

// Parser
void	ft_paraser(char *input, t_lexer *lexer);
int		check_files(char *input, t_lexer *lexer);
int		get_args(char *input, t_lexer *lexer);
void	parse_cmds(char *input, t_lexer *lexer);
void	resolve_path(void);

// Exeggutor
void	ft_exeggutor(void);

// Util Functions
int		special_chars(char c);
void	print_list(t_lexer *head);
void	print_file_list(t_infile *in_head, t_outfile *out_head);
void	ft_free_char(char **src);
void	free_cmds(char **commands);

// Builtins
int		run_builtins(void);
int		pwd(void);
void	echo(void);

#endif
