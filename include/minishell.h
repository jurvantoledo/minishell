/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-tol <jvan-tol@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/06 14:39:42 by jvan-tol      #+#    #+#                 */
/*   Updated: 2022/12/21 16:48:05 by jvan-tol      ########   odam.nl         */
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

typedef struct s_command {
	char				*path;
	char				**arguments;
	bool				invalid;
	int					fd_in;
	int					fd_out;
}	t_command;

typedef struct s_lexer {
	t_token_type		type;
	int					length;
	int					index;
	bool				adjacent;
	bool				expanded;
	struct s_lexer		*next;
}	t_lexer;

typedef struct s_shell
{
	t_env		*env;
	int			exit_code;
	bool		expanded_exit;
	size_t		cmd_len;
	pid_t		pid;
	t_lexer		*lexer;
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

// Free env
int		remove_node(t_env **head, char *key);
t_env	*clear_list(t_env **head);

/* -----------------> Lexer Functions <--------------- */
t_lexer	*ft_snorlexer(char *input);
int		check_quotes(int end);
void	post_process(char *input, t_lexer *lexer);
int		ft_lexer_wrlength(char *input);
int		ft_symbol_len(char *input);
int		search_end_quote(char *input);
char	*ft_is_adjacent(char *input, t_lexer *lexer);
bool	clear_token_list(t_lexer **head);
bool	check_expander(char *input);
bool	check_double_quotes(char *input);
bool	ft_idk(char *input, char *str);

/* -----------------> Parser Functions <--------------- */
int		ft_paraser(char *input, t_lexer *lexer);
int		parse_files(char *input, t_lexer *lexer);
int		parse_cmds(char *input, t_lexer *lexer);
char	**adjacent_args(char **args, char *str);
int		check_builtin(char *command);
char	*parse_path(char *cmd);
int		resolve_path(void);
void	purge_commands(void);

/* -----------------> Expander <------------------ */
char	*expand_dollar(char *input);
char	*ft_replace(char *before, char *oldsub, char *newsub);
char	*get_env_dollar(char *input);

/* -----------------> Exeggutor Functions <--------------- */
int		ft_exeggutor(void);
int		ft_pipe(int fds[2]);
int		ft_fork(pid_t *pid);
int		set_shlvl(void);
int		arg_files_check(char *arg);
void	ft_exec_error(int i);
void	ft_wait(int status);

/* -----------------> Util Functions <--------------- */
void	print_list(t_lexer *head);
int		special_chars(char c);
void	ft_free_char(char **src);
int		ft_iscapital(int c);

/* -----------------> Builtin Functions <--------------- */
int		exec_builtins(int i);

// PWD builtin
int		builtin_pwd(void);
int		print_old_pwd(void);

// ECHO builtin
int		builtin_echo(int argc, char **args);

// ENV builtin
int		builtin_env(int argc, char **argv);

// UNSET builtin
int		builtin_unset(int argc, char **args);

// EXPORT builtin
int		builtin_export(int argc, char **args);
int		check_val_quotes(char *val);
int		args_identifier(char *args);

// EXIT builtin
int		builtin_exit(int argc, char **argv);

// CD Builtin
int		builtin_cd(int argc, char **argv);
int		cd_home_path(t_env *dir, char *path);
int		set_path(char *path);
int		set_old_cd(void);

int		errors(char *shell, char *arg, char *str, int exit_code);

/* ----------------> Signals <-------------------- */
void	sig_handler_exec(int sig);
void	init_signal(void);

void	sig_ignore(void);

#endif
