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
CFLAGS		= -Wall -Werror -Wextra -Wunreachable-code
MAKEFLAGS	= --no-print-directory
VALG		= valgrind -s --leak-check=full
RM			= rm -rf
MKDIR		= mkdir -p
HEADERS		= -I include -I ~/.brew/opt/readline/include
ARCHIVES	= -lreadline -L ~/.brew/opt/readline/lib

#===============================================================================: Sourcefiles

SRCS =	src/main.c \
		src/utils/utils.c \
		src/utils/free.c \
		src/env/env.c \
		src/env/free_env.c \
		src/env/env_utils.c \
		src/lexer/lexer.c \
		src/lexer/check.c \
		src/lexer/quotes.c \
		src/lexer/post_process.c \
		src/lexer/clear_lexer.c \
		src/expander/expander.c \
		src/expander/replace.c \
		src/expander/check_expand.c \
		src/parse/parse.c \
		src/parse/parse_files.c \
		src/parse/parse_cmds.c \
		src/parse/parse_cmds_utils.c \
		src/parse/parse_adjacent.c \
		src/parse/parse_path.c \
		src/parse/free_cmds.c \
		src/exeggutor/exec_utils.c \
		src/exeggutor/exeggutor.c \
		src/exeggutor/shlvl.c \
		src/builtins/builtin_pwd.c \
		src/builtins/builtin_echo.c \
		src/builtins/builtin_env.c \
		src/builtins/builtin_unset.c \
		src/builtins/builtin_export.c \
		src/builtins/builtin_export_utils.c \
		src/builtins/builtins_exit.c \
		src/builtins/builtin_cd.c \
		src/builtins/builtin_cd_utils.c \
		src/builtins/errors.c \
		src/builtins/exec.c \
		src/signals/signals.c \
		include/gnl/get_next_line_utils.c \
		include/gnl/get_next_line.c

#===============================================================================: Make commands
all: libft message $(NAME)

#===============================================================================: Main compile
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(HEADERS) $(ARCHIVES) $(LIBFT)/libft.a -o $(NAME)
	@printf "$(GREEN)✅Executable \"$(NAME)\" created$(RESET)\n\n"

#===============================================================================: C file compile
objs/%.o: src/%.c
	@$(MKDIR) objs
	@$(MKDIR) objs/parse
	@$(MKDIR) objs/lexer
	@$(MKDIR) objs/expander
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
	@cd include/libft/ && git pull
	@cd include/libft/ && git push

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
	@$(RM) include/gnl/get_next_line_utils.o
	@$(RM) include/gnl/get_next_line.o
	@$(MAKE) -C $(LIBFT) fclean
	@printf "$(RED)🧹Removed objects for \"$(NAME)\"!$(RESET)\n"
	@printf "$(RED)🧹Removed \"$(NAME)\"!$(RESET)\n"

#===============================================================================: Remove all object files, executable and remake executable
re: fclean all

#===============================================================================: To not confuse make
.PHONY: all, clean, fclean, re, message, run