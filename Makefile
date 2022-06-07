
##		THE TARGETS			##
NAME		= 	minishell

##		THE DIRECTORIES		##
SRC_DIR		:=	src/
OBJ_DIR		:= 	build/
INC_DIR		:= 	includes/

##		THE LIBFT			##
LIBFT_HEADER	:=	./libft/includes
LIBFT_DIRECTORY :=	./libft
LIBFT			:=	$(LIBFT_DIRECTORY)/libft.a

##		COMPILATION			##
CC := gcc
READLIB := -lreadline -L /opt/homebrew/opt/readline/lib -I .brew/opt/readline/include
# -lreadline -L $(HOME)/.brew/opt/readline/lib
# -lreadline -L /opt/homebrew/opt/readline/lib -I .brew/opt/readline/include
LIBRAIRIES := -lft -L$(LIBFT_DIRECTORY) $(READLIB)
CFLAGS := -Wall -Wextra -Werror -g3 -fsanitize=address

##		INCLUDES			##
CFLAGS	+= -I$(INC_DIR) -I$(LIBFT_HEADER)

SUBDIR	:=	src													\
			src/shell								 			\
			src/shell/sub_system								\
			src/shell/sub_system/terminal						\
			src/shell/sub_system/error							\
			src/shell/parsing									\
			src/shell/parsing/utils								\
			src/shell/parsing/tokenizer							\
			src/shell/execution									\
			src/shell/execution/commands						\
			src/shell/execution/commands/creation				\
			src/shell/execution/commands/expansion				\
			src/shell/execution/commands_execution				\
			src/shell/execution/commands_execution/binary_tree	\
			src/builtin											\
			src/shell/sub_system/env							\
			src/shell/sub_system/wildcard						\


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

SRCS = 																			\
	./src/main.c																\
	./src/shell/sub_system/error/error.c										\
	./src/shell/sub_system/terminal/signal.c									\
	./src/shell/sub_system/terminal/signal_utils.c								\
	./src/shell/sub_system/terminal/terminal.c									\
	./src/shell/sub_system/terminal/cleaning.c									\
	./src/shell/parsing/input.c													\
	./src/shell/parsing/utils/quote.c											\
	./src/shell/parsing/utils/token.c											\
	./src/shell/parsing/utils/other.c											\
	./src/shell/parsing/utils/character.c										\
	./src/shell/parsing/tokenizer/tokenizer.c									\
	./src/shell/parsing/tokenizer/tokenizer_utils.c								\
	./src/shell/parsing/tokenizer/token_attribution.c							\
	./src/shell/execution/commands/creation/commands.c							\
	./src/shell/execution/commands/creation/commands_utils.c					\
	./src/shell/execution/commands/creation/commands_arguments.c				\
	./src/shell/execution/commands/creation/commands_redirection.c				\
	./src/shell/execution/commands/expansion/expansion.c						\
	./src/shell/execution/commands_execution/here_doc.c							\
	./src/shell/execution/commands_execution/commands_execution.c				\
	./src/shell/execution/commands_execution/operators_execution.c				\
	./src/shell/execution/commands_execution/pipeline_execution.c				\
	./src/shell/execution/commands_execution/redirections_execution.c			\
	./src/shell/execution/commands_execution/binary_tree/binary_tree.c			\
	./src/shell/execution/commands_execution/binary_tree/binary_tree_utils.c	\
	./src/builtin/exit.c														\
	./src/builtin/pwd.c															\
	./src/builtin/cd.c															\
	./src/builtin/echo.c														\
	./src/shell/sub_system/env/lstenv.c											\
	./src/shell/sub_system/env/lstenv_utils.c									\
	./src/shell/sub_system/env/addenv.c											\
	./src/shell/sub_system/env/environment.c									\
	./src/shell/sub_system/env/replace_dollar.c									\
	./src/builtin/export.c														\
	./src/builtin/export_utils.c												\
	./src/builtin/unset.c														\
	./src/shell/execution/commands_execution/execution_base.c					\
	./src/shell/execution/commands_execution/execution_base_utils.c				\
	#./src/shell/parsing/utils/print.c											\

HEADERS = \
	./includes/minishell.h			\
	./includes/sub_system/terminal.h\
	./includes/parsing/parsing.h	\
	./includes/parsing/tokens.h		\
	./includes/execution/command.h	\
	./includes/execution/execution.h \

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
		@$(CC) $(CFLAGS)  $(OBJS) -o $(NAME) $(LIBRAIRIES) $(LIBFT)
		@printf "$(YEL)------------Linked------------------\n$(RESET)"
		@printf " $(READLIB) $(RESET)\n"
		@printf "$(GREEN)$(NAME) sucessfully created ! $(RESET)\n"
clean:
		@printf "\n $(RED)removing:\n 		$(RESET) $(NAME) *.o\n$(RESET)"
		@rm -rf $(OBJ_DIR)
		@make -C $(LIBFT_DIRECTORY) clean
fclean: clean
		@printf "		$(RESET) $(NAME)\n"
		@make -C $(LIBFT_DIRECTORY) clean
		@rm -rf $(NAME)
		

re: fclean all

lldb:
	$(CC) -g $(SRCS) $(CFLAGS) -o $(NAME) $(LIBRAIRIES) $(LIBFT)
	lldb $(NAME)

run: $(NAME)
		./$(NAME)
.PHONY: all run clean fclean re
