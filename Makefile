NAME	= minishell
SRC_DIR	:= src/
OBJ_DIR	:= build/
INC_DIR	:= includes/


CC := gcc
READLIB := -lreadline
CFLAGS := -Wall -Wextra -Werror

CFLAGS	+= -I $(INC_DIR)
SUBDIR	:=	src/ src/main src/folder src/parsing


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
	./src/folder/terminal.c \
	./src/main/main.c \
	./src/parsing/parsing_1.c \

HEADERS = \
	./includes/minishell.h\

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

$(NAME): $(SRCS) $(OBJS)
		@printf "$(YEL)\n------------Compiled----------------\n$(RESET)"
		@printf "$(RESET)$(CC) $(CFLAGS)\n"
		@$(CC) $(CFLAGS) $(READLIB) $(OBJS) -o $(NAME)
		@printf "$(YEL)------------Linked------------------\n$(RESET)"
		@printf " $(READLIB) $(RESET)\n"
		@printf "$(GREEN)$(NAME) sucessfully created ! $(RESET)\n"

clean:
		@printf "\n $(RED)removing: $(RESET) $(OBJ_DIR)\n$(RESET)"
		@rm -rf $(OBJ_DIR)
fclean: clean
		@printf "\n $(RED)removing: $(RESET) $(NAME)\n"
		@rm -rf $(NAME)

re: fclean all

run: $(NAME)
		./$(NAME)
.PHONY: all run clean fclean re
