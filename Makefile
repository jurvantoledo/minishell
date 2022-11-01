# NAME = minishell
# CC = gcc
# HEADERS	= -I .brew/opt/readline/include
# ARCHIVES = -L .brew/opt/readline/lib
# INCLUDE = include
# LIBFT_DIR = $(INCLUDE)/libft
# LIBFT = $(LIBFT_DIR)/libft.a

# SRC =	src/main.c \
# 		src/utils/utils.c \
# 		src/utils/free.c \
# 		src/env/env.c \
# 		src/env/free_env.c \
# 		src/env/env_utils.c \
# 		src/lexer/lexer.c \
# 		src/lexer/check.c \
# 		src/lexer/post_process.c \
# 		src/parse/parse.c \
# 		src/parse/parse_files.c \
# 		src/parse/parse_cmds.c \
# 		src/parse/parse_path.c \
# 		src/exeggutor/exeggutor.c \
# 		src/builtins/run.c \
# 		src/builtins/builtin_pwd.c \
# 		src/builtins/builtin_echo.c \
# 		src/builtins/builtin_env.c \
# 		src/builtins/builtin_unset.c \
# 		src/builtins/builtin_export.c \
# 		src/builtins/builtins_exit.c \
# 		src/builtins/builtin_cd.c \
# 		src/builtins/exec.c \
# 		src/signals/signals.c

# OBJ = $(SRC:%.c=%.o)

# all: $(NAME)

# $(NAME): $(OBJ) $(LIBFT)
# 	$(CC) $(OBJ) $(HEADERS) $(ARCHIVES) $(LIBFT) -lreadline -o $(NAME)

# %.o: %.c
# 	$(CC) $(FLAGS) -c $< -o $@

# $(LIBFT):
# 	$(MAKE) -C $(LIBFT_DIR)

# clean:
# 	$(MAKE) fclean -C $(LIBFT_DIR)
# 	rm -f $(OBJ)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re


# ------------------------------

#===============================================================================: Filename
NAME		= minishell

#===============================================================================: Source to object conversion location
OBJS		= $(subst src, objs, $(SRCS:.c=.o))

#===============================================================================: Color codes
GREEN		= \033[1;32m
RED			= \033[1;31m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
RESET		= \033[0m

#===============================================================================: Include files
LIBFT		= include/libft

#===============================================================================: Compile variables
CC			= gcc
# CFLAGS		= -Wall -Werror -Wextra -Wunreachable-code 
MAKEFLAGS	= --no-print-directory
VALG		= valgrind -s --leak-check=full
RM			= rm -rf
MKDIR		= mkdir -p
HEADERS		= -I include -I ~/.brew/opt/readline/include
ARCHIVES	= -lreadline -L ~/.brew/opt/readline/lib

#===============================================================================: Sourcefiles
# SRCS		= $(addprefix src/, $(addsuffix .c, \
# 				main \
# 			$(addprefix lexer/, \
# 				lexer \
# 				check \
# 				post_process) \
# 			$(addprefix parsing/, \
# 				parser \
# 				parse_cmds \
# 				parse_files \
# 				parse_path) \
# 			$(addprefix exeggutor/, \
# 				exec) \
# 			$(addprefix env/, \
# 				env \
# 				free_env \
# 				env_utils) \
# 			$(addprefix builtins/, \
# 				builtin_cd \
# 				builtin_echo \
# 				builtin_env \
# 				builtin_exit \
# 				builtin_export \
# 				builtin_pwd \
# 				builtin_unset) \
# 			$(addprefix signals/, \
# 				signals)


SRCS =	src/main.c \
		src/utils/utils.c \
		src/utils/free.c \
		src/env/env.c \
		src/env/free_env.c \
		src/env/env_utils.c \
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
		src/builtins/builtin_export.c \
		src/builtins/builtins_exit.c \
		src/builtins/builtin_cd.c \
		src/builtins/exec.c \
		src/signals/signals.c

#===============================================================================: Make commands
all: libft message $(NAME)

#===============================================================================: Main compile
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(HEADERS) $(ARCHIVES) $(LIBFT)/libft.a -lreadline -o $(NAME)
	@printf "$(GREEN)✅Executable \"$(NAME)\" created$(RESET)\n\n"

#===============================================================================: C file compile
objs/%.o: src/%.c
	@$(MKDIR) objs
	@$(MKDIR) objs/parse
	@$(MKDIR) objs/lexer
	@$(MKDIR) objs/env
	@$(MKDIR) objs/builtins
	@$(MKDIR) objs/signals
	@$(MKDIR) objs/utils
	@$(MKDIR) objs/exeggutor
	@$(CC) -o $@ -c $< $(HEADERS)
ifeq ($(DB),1)
	@printf "$(GREEN)\r🔨Compiling: $(MAGENTA)$(notdir $<)$(GREEN)\r\e[35C[OK]\n$(RESET)"
endif

#===============================================================================: Executable run command
valg: all
	@printf "$(GREEN)Executing $(NAME) with Valgrind\n$(RESET)\n"
	@$(VALG) ./$(NAME)

# fsan: CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3
# fsan: all
# 	@printf "$(GREEN)Executing $(NAME) with fsanitize\n$(RESET)\n"
# 	@./$(NAME)

submodules:
	@git submodule update --init --recursive
	@cd libs/libft/ && git pull
	@cd libs/libft/ && git push

#===============================================================================: Build messages
message:
	@printf "$(MAGENTA)🔨Building \"$(NAME)\"\n$(RESET)\n"

#===============================================================================: Libft Compile
libft:
	@$(MAKE) -C $(LIBFT) $(MAKEFLAGS)

#===============================================================================: Remove all object files
clean:
	@$(RM) objs/
	@$(MAKE) -C $(LIBFT) clean
	@printf "$(RED)🧹Removed objects for \"$(NAME)\"!$(RESET)\n"

#===============================================================================: Remove all object files and executable
fclean:
	@$(RM) objs/
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@printf "$(RED)🧹Removed objects for \"$(NAME)\"!$(RESET)\n"
	@printf "$(RED)🧹Removed \"$(NAME)\"!$(RESET)\n"

#===============================================================================: Remove all object files, executable and remake executable
re: fclean all

#===============================================================================: To not confuse make
.PHONY: all, clean, fclean, re, message, run