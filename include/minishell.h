/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:39:42 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/11/07 15:57:26 by jvan-tol      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <signal.h>
# include <errno.h>
# include <termios.h>
# include <sys/wait.h>
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"

# define MINISHELL_H
# define SPECIAL_CHAR "|<>"
# define MAX_PATH 256
# define SHELL_NAME "[terminal cancer]: "

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
	char		**envp;
	size_t		cmd_len;
	pid_t		pid;
	t_lexer		*lexer;
	t_files		*files;
	t_command	*command;
}	t_shell;

extern t_shell	g_shell;

int		main(int argc, char *argv[], char *envp[]);

/* --------> Envp parser for storing the keys and values of envp <---------- */
t_env	*parse_env(char *envp[]);
t_env	*get_env(t_env *head, char *pathname);
char	**set_env(void);
size_t	env_len(void);
void	sort_env(t_env **head, t_env *new);

// Adding to env list
int		add_env(t_env **head, char *env);
int		add_str_env(t_env *env, char *str);
int		add_env_var(t_env **head, char *var_str);
int		strenv(char **res, t_env *env);

// Update env list
int		update_env(t_env *head, char *val, char *new_val);

// Free env
int		remove_node(t_env **head, char *key);
t_env	*clear_list(t_env **head);

/* -----------------> Lexer Functions <--------------- */
t_lexer	*ft_snorlexer(char *input);
int		check_quotes(char *input);
void	post_process(char *input, t_lexer *lexer);
int		check_input(char *input, int i);

/* -----------------> Parser Functions <--------------- */
void	ft_paraser(char *input, t_lexer *lexer);
int		check_files(char *input, t_lexer *lexer);
int		get_args(char *input, t_lexer *lexer);
void	parse_cmds(char *input, t_lexer *lexer);
void	resolve_path(void);

/* -----------------> Exeggutor Functions <--------------- */
void	ft_exeggutor(void);
int		ft_pipe(int fds[2]);
int		ft_fork(pid_t *pid);

/* -----------------> Util Functions <--------------- */
int		special_chars(char c);
void	print_list(t_lexer *head);
void	print_file_list(t_infile *in_head, t_outfile *out_head);
void	ft_free_char(char **src);
void	free_cmds(char **commands);

/* -----------------> Builtin Functions <--------------- */
void	exec_builtins(void);
int		run_builtins(void);

// PWD builtin
int		builtin_pwd(void);
int		print_old_pwd(void);

void	builtin_echo(int argc, char **args);
int		builtin_env(int argc, char **argv);
int		builtin_unset(int argc, char **args);
void	builtin_export(int argc, char **args);
void	builtin_exit(int argc, char **argv);

// CD Builtin
int		builtin_cd(int argc, char **argv);
int		cd_home_path(t_env *dir, char *path);
int		set_path(char *path);
int		set_old_cd(char *path);

int		errors(char *var, char *str, int exit_code);

/* ----------------> Signals <-------------------- */
// void	signals(void);
// void	sig_handler(int signum);
void	set_sigs_exec(void);
void	sig_handler_exec(int sig);
void	init_signal(void);
void	set_signals(void);

#endif
