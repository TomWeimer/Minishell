
##		THE TARGETS			##
NAME		= 	minishell
ECHO		=	bin/echo
EXIT		= 	bin/exit

##		THE DIRECTORIES		##
SRC_DIR		:=	src/
OBJ_DIR		:= 	build/
INC_DIR		:= 	includes/

##		THE LIBFT			##
LIBFT_HEADER	:=	./libft
LIBFT_DIRECTORY :=	./libft
LIBFT			:=	$(LIBFT_DIRECTORY)/libft.a

##		EXECUTABLES			##
ECHO_SRC		:=	./src/bin/echo.c
ECHO_DIR		:=	./bin
EXIT_SRC		:=	./src/bin/exit.c
EXIT_DIR		:=	./bin

##		COMPILATION			##
CC := gcc
READLIB :=  -lreadline -L /opt/homebrew/opt/readline/lib -I .brew/opt/readline/include
LIBRAIRIES := -lft -L$(LIBFT_DIRECTORY) $(READLIB)
CFLAGS := -Wall -Wextra -Werror

##		INCLUDES			##
CFLAGS	+= -I$(INC_DIR) -I$(LIBFT_HEADER)

SUBDIR	:=	src/ src/bin src/shell						\
		 	src/shell/start src/shell/signal			\
			src/shell/process src/shell/execution		\
			src/shell/end								\

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
	./src/shell/start/parsing.c \
	./src/shell/start/terminal.c \
	./src/shell/start/utils.c \
	./src/shell/execution/execution_utils.c \
	./src/shell/execution/execution.c \
	./src/shell/signal/signal_utils.c \
	./src/shell/signal/signal_handler.c \
	./src/shell/process/process.c \
	./src/shell/process/process_utils.c \
	./src/main.c \

HEADERS = \
	./includes/minishell.h\
	./libft/libft.h\

###▲▲▲<src-updater-do-not-edit-or-remove>▲▲▲


SRC = $(notdir $(SRCS))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR),$(OBJ))

VPATH := $(SRC_DIR) $(OBJ_DIR) $(SUBDIR)
all: $(NAME) $(ECHO) $(EXIT)

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

$(ECHO):	$(ECHO_SRC)
		$(CC) $(ECHO_SRC) -o $(ECHO)

$(EXIT):	$(EXIT_SRC)
		$(CC) $(EXIT_SRC) -o $(EXIT)
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
