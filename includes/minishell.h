#ifndef MINISHELL_H
# define MINISHELL_H

// librairies:
# include <stdio.h>
 #include <signal.h>
 #include <dirent.h>
 #include <sys/types.h>
#include <sys/wait.h>

// headers:
# include	"../libft/libft.h"
# include	"parsing/tokens.h"
# include	"execution/command.h"
# include	"sub_system/error.h"
# include 	"environment/env.h"


// define:
int g_print;
char **g_envp;
# define RUNNING 1

// prototypes:
void no_prompt(int sig);
void new_prompt(int sig);
void handler_child(int sig);
void			ft_wildcard(t_command *cmd);
char			*ft_asterix(void);
void			init_terminal(void);
char			*get_user_input(void);
t_group	*tokenizer(char *input);
t_command		**shell_commands(t_group *all_tokens);
void 			shell_execution(t_group *all_token, t_command **all_command, t_env *env);
void 			clean_tokens(t_group *all_token);
void			clean_commands(t_command **all_commands);
#endif