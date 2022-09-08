NAME = minishell
CC = gcc
FLAGS = -lreadline
INCLUDE = include
LIBFT_DIR = $(INCLUDE)/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC =	src/main.c \
		src/env/env_parser.c \
		src/lexer/lexer.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

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