#ifndef MINISHEL_H
# define MINISHEL_H
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <unistd.h>
 #include <signal.h>
void	ft_prompt(char **envp);
void	ft_ctrl(char **envp);
void 	ft_test (int sig);

#endif
