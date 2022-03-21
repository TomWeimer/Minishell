#ifndef MINISHELL_H
# define MINISHELL_H

# define RUNNING 1
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
 #include <stdlib.h>
void ft_terminal(void);
void parsing(int *exit, char *line);
#endif