NAME	= minishell
SRC_DIR	:= src/
OBJ_DIR	:= build/
INC_DIR	:= includes/

SUBDIR	:=	src/ src//main src//folder

###▼▼▼<src-updater-do-not-edit-or-remove>▼▼▼
# **************************************************************************** #
# **   Generated with https://github.com/lorenuars19/makefile-src-updater   ** #
# **************************************************************************** #

SRCS = \
	./src/folder/terminal.c \
	./src/main/main.c \

HEADERS = \
	./includes/minishell.h\

###▲▲▲<src-updater-do-not-edit-or-remove>▲▲▲

SRC = $(notdir $(SRCS))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR),$(OBJ))

VPATH := $(SRC_DIR) $(OBJ_DIR) $(SUBDIR)

all: $(NAME)

$(OBJ_DIR)%.o: %.c $(HEADERS)
			mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRCS) $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
		rm -rf $(OBJ_DIR)
fclean: clean
		rm -rf $(NAME)

re: fclean all

run: $(NAME)
		./$(NAME)
.PHONY: all run clean fclean re
