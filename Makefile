NAME = minishell
CC = gcc
FLAGS = -lreadline
INCLUDE = include
LIBFT_DIR = $(INCLUDE)/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC =	src/main.c \
		src/utils/utils.c \
		src/utils/free.c \
		src/env/env.c \
		src/env/free_env.c \
		src/lexer/lexer.c \
		src/lexer/check.c \
		src/lexer/post_process.c \
		src/parse/parse.c \
		src/parse/parse_files.c \
		src/parse/parse_cmds.c \
		src/parse/parse_path.c \
		src/exeggutor/exeggutor.c \
		src/builtins/run.c \
		src/builtins/builtin_pwd.c \
		src/builtins/builtin_echo.c \
		src/builtins/builtin_env.c \
		src/builtins/builtin_unset.c \
		src/builtins/exec.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(FLAGS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re