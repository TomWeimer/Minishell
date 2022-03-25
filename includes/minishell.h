#ifndef MINISHELL_H
# define MINISHELL_H

# define TRUE 1
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <signal.h>
# include <errno.h>
#include "libft.h"

#define	MALLOC "Error: failed to allocate memmory\n"
#define	SIZE_ERROR	34

typedef struct sigaction t_signal;
void ft_terminal(void);
void parsing_input(char *line);
void new_signal(t_signal *sa, void *ptr_function);
void	signal_handler(int sig);
int *get_status(int nb);
void message_error(char *str);
void child_event(int sig);
void parent_event(int sig);
void	init_terminal(char **input);



typedef struct s_input
{
	int		nb;
	pid_t	*pid;
	int 	*status;
	int		parent_status;
}t_input;
void cmd_process(char **input, t_input *info);
int		**get_pipeline(int nb);
pid_t	*get_pid(int nb);
int		get_pipe_nb(char **input);
void	close_unused_pipes(int process_num, int nb, int **pipeline);
void	close_all_pipes(int nb, int **pipeline);
void	free_all_pipes(int nb, int **pipeline);
void	init_terminal(char **input);
void	execute(char *cmd);
void	rl_replace_line(const char *, int);
void 	ft_signal(int sig);
#endif