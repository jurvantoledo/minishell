/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:39:42 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/07 12:49:51 by jvan-tol      ########   odam.nl         */
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
# define READ 0
# define WRITE 1
# define SHELL_NAME "[shellus cancerus]: "

typedef enum e_token_type {
	INFILE,
	OUTFILE,
	OUTFILE_APPEND,
	HERE_DOC,
	ARGUMENT,
	PIPE,
	COMMAND,
	DOLLAR,
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
	int					fd_in;
	int					fd_out;
}	t_command;

typedef struct s_lexer {
	t_token_type		type;
	int					length;
	int					index;
	bool				adjacent;
	bool				expanded;
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

/* --------> Main functions <---------- */

int		main(int argc, char *argv[], char *envp[]);
int		clean_shell(t_lexer *lexer, int exit, bool exit_prog);

/* --------> Env List functions <---------- */
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
char	*check_new_env_var(char *str);

// Free env
int		remove_node(t_env **head, char *key);
t_env	*clear_list(t_env **head);

/* -----------------> Lexer Functions <--------------- */
t_lexer	*ft_snorlexer(char *input);
int		check_quotes(int end);
void	post_process(char *input, t_lexer *lexer);
int		check_input(char *input, int i);
int		search_end_quote(char *input);
int		ft_adjacent(char *input, t_lexer *lexer);
char	*ft_is_adjacent(char *input, t_lexer *lexer);
bool	clear_token_list(t_lexer **head);

/* -----------------> Parser Functions <--------------- */
int		ft_paraser(char *input, t_lexer *lexer);
int		parse_files(char *input, t_lexer *lexer);
int		get_args(char *input, t_lexer *lexer);
int		parse_cmds(char *input, t_lexer *lexer);
char	**expanded_args(char **args, char *str);
bool	maybe_expand(char *str);
int		check_builtin(char *command);
char	*parse_path(char *cmd);
int		resolve_path(void);
void	purge_commands(void);

/* -----------------> Exeggutor Functions <--------------- */
int		ft_exeggutor(void);
int		ft_pipe(int fds[2]);
int		ft_fork(pid_t *pid);
int		set_shlvl(void);
int		arg_files_check(char *arg);
int		arg_files_permission(void);
void	ft_wait(void);

/* -----------------> Util Functions <--------------- */
int		special_chars(char c);
void	print_list(t_lexer *head);
void	ft_free_char(char **src);
void	free_cmds(char **commands);
void	ft_remove_commands(void);
int		ft_iscapital(int c);

/* -----------------> Builtin Functions <--------------- */
int		exec_builtins(int i);
int		run_builtins(void);

// PWD builtin
int		builtin_pwd(void);
int		print_old_pwd(void);

// ECHO builtin
int		builtin_echo(int argc, char **args);
int		check_arg_env(char *arg);
char	*get_env_arg(char *arg);

// ENV builtin
int		builtin_env(int argc, char **argv);

// UNSET builtin
int		builtin_unset(int argc, char **args);

// EXPORT builtin
int		builtin_export(int argc, char **args);
int		check_val_quotes(char *val);
int		args_identifier(char *args);
char	*check_env_key(char *str);

// EXIT builtin
int		builtin_exit(int argc, char **argv);

// CD Builtin
int		builtin_cd(int argc, char **argv);
int		cd_home_path(t_env *dir, char *path);
int		set_path(char *path);
int		set_old_cd(void);

int		expand_dollar(char *input);
int		errors(char *shell, char *arg, char *str, int exit_code);

/* ----------------> Signals <-------------------- */
// void	signals(void);
// void	sig_handler(int signum);
void	set_sigs_exec(void);
void	sig_handler_exec(int sig);
void	init_signal(void);
void	set_signals(void);

void	sig_ignore(void);

#endif
