
##		THE TARGETS			##
NAME		= 	minishell

##		THE DIRECTORIES		##
SRC_DIR		:=	src/
OBJ_DIR		:= 	build/
INC_DIR		:= 	includes/

##		THE LIBFT			##
LIBFT_HEADER	:=	./libft
LIBFT_DIRECTORY :=	./libft
LIBFT			:=	$(LIBFT_DIRECTORY)/libft.a

##		EXECUTABLES			##


##		COMPILATION			##
CC := gcc
READLIB :=  -lreadline -L /opt/homebrew/opt/readline/lib -I .brew/opt/readline/include
LIBRAIRIES := -lft -L$(LIBFT_DIRECTORY) $(READLIB)
CFLAGS := -Wall -Wextra -Werror

##		INCLUDES			##
CFLAGS	+= -I$(INC_DIR) -I$(LIBFT_HEADER)

SUBDIR	:=	src/\
			src/builtin\
			src/commands	src/commands/creation src/commands/expansion\
			src/env\
			src/error\
			src/execution src/execution/binary_tree src/execution/command_execution \
			src/parsing src/parsing/tokenizer src/parsing/utils \
			src/signals

RED		= \033[1;31m
YEL		= \033[1;33m
BLU		= \033[1;34m
WHITE	= \033[1;37m
GREEN	= \033[1;32m
RESET	= \033[0m

###▼▼▼<src-updater-do-not-edit-or-remove>▼▼▼
# **************************************************************************** #
# **   Generated with https://github.com/lorenuars19/makefile-src-updater   ** #
# **************************************************************************** #

SRCS = \
	./src/signals/signal.c \
	./src/main.c \
	./src/execution/binary_tree/binary_tree.c \
	./src/execution/binary_tree/binary_tree_utils.c \
	./src/execution/command_execution/operator_execution.c \
	./src/execution/command_execution/command_execution.c \
	./src/execution/command_execution/redirection_execution.c \
	./src/execution/command_execution/pipeline_execution.c \
	./src/commands/expansion/expansion.c \
	./src/commands/creation/commands_redirection.c \
	./src/commands/creation/commands_utils.c \
	./src/commands/creation/commands_arguments.c \
	./src/commands/creation/commands.c \
	./src/parsing/tokenizer/token_attribution.c \
	./src/parsing/tokenizer/tokenizer_utils.c \
	./src/parsing/tokenizer/tokenizer.c \
	./src/parsing/utils/print.c \
	./src/parsing/utils/token.c \
	./src/parsing/utils/quote.c \
	./src/parsing/utils/other.c \
	./src/parsing/utils/character.c \
	./src/parsing/input.c \
	./src/error/error.c \
	./src/builtin/exit.c \
	./src/builtin/pwd.c \
	./src/builtin/cd.c \
	./src/builtin/echo.c \
	#./src/env/lstenv.c \
	#./src/env/addenv.c \
	#./src/env/environment.c \
	#./src/builtin/export.c \
	#./src/builtin/unset.c 
HEADERS = \
	./includes/env.h\
	./includes/syntax.h\
	./includes/minishell.h\
	./includes/tokens.h\
	./includes/binary_tree.h\
	./includes/command.h\

###▲▲▲<src-updater-do-not-edit-or-remove>▲▲▲


SRC = $(notdir $(SRCS))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR),$(OBJ))

VPATH := $(SRC_DIR) $(OBJ_DIR) $(SUBDIR)
all: $(NAME)

$(OBJ_DIR)%.o: %.c $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -c $< -o $@
			@printf "$(RESET)"
$(LIBFT):
		@echo "$(YEL)			LIBFT MAKING...\n$(RESET)"
		@make -C $(LIBFT_DIRECTORY)

$(NAME): $(LIBFT) $(SRCS) $(OBJS)
		@printf "$(YEL)\n------------Compiled----------------\n$(RESET)"
		@printf "$(RESET)$(CC) $(CFLAGS)\n"
		@$(CC) $(CFLAGS)  $(OBJS) -o $(NAME) $(LIBRAIRIES)
		@printf "$(YEL)------------Linked------------------\n$(RESET)"
		@printf " $(READLIB) $(RESET)\n"
		@printf "$(GREEN)$(NAME) sucessfully created ! $(RESET)\n"
clean:
		@printf "\n $(RED)removing: $(RESET) $(OBJ_DIR)\n$(RESET)"
		@rm -rf $(OBJ_DIR)
		@make -C $(LIBFT_DIRECTORY) clean
fclean: clean
		@printf "\n $(RED)removing: $(RESET) $(NAME)\n"
		@make -C $(LIBFT_DIRECTORY) clean
		@rm -rf $(NAME)
		

re: fclean all

run: $(NAME)
		./$(NAME)
.PHONY: all run clean fclean re
