NAME	:=	minishell

CC		:=	gcc -Wall -Wextra -Werror
LIBFT = ./libft
LIBFTFLAGS = -L $(LIBFT) -lft
SRCS	:=	src/main.c										\
			src/commands/creation/commands.c				\
			src/commands/creation/commands_arguments.c		\
			src/commands/creation/commands_utils.c			\
			src/commands/creation/commands_redirection.c	\
			src/commands/expansion/expansion.c	\
			src/execution/binary_tree/binary_tree.c			\
			src/execution/binary_tree/binary_tree_utils.c		\
			src/execution/command_execution/command_execution.c		\
			src/execution/command_execution/operator_execution.c		\
			src/execution/command_execution/pipeline_execution.c		\
			src/execution/command_execution/redirection_execution.c		\
			src/parsing/tokenizer/token_attribution.c					\
			src/parsing/tokenizer/tokenizer_utils.c					\
			src/parsing/tokenizer/tokenizer.c					\
			src/parsing/utils/character.c					\
			src/parsing/utils/quote.c						\
			src/parsing/utils/print.c						\
			src/parsing/utils/token.c						\
			src/parsing/utils/other.c						\
			src/parsing/input.c 							\
			src/signals/signal.c 							\
			src/error/error.c								\
			src/builtin/cd.c								\
			src/builtin/echo.c								\
			src/builtin/exit.c								\
			src/builtin/pwd.c														

READLIB :=  -lreadline -L /opt/homebrew/opt/readline/lib -I .brew/opt/readline/include

OBJS	:= $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(READLIB) $(LIBFTFLAGS) -o $(NAME)
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)