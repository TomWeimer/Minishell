#ifndef MINISHELL_H
# define MINISHELL_H

// librairies:
# include <stdio.h>
 #include <signal.h>

// headers:
# include	"../libft/libft.h"
# include	"parsing/tokens.h"
# include	"execution/command.h"
# include	"sub_system/error.h"


// define:
# define RUNNING 1

// prototypes:
void			init_terminal(void);
char			*get_user_input(void);
t_group	*tokenizer(char *input);
t_command		**shell_commands(t_group *all_tokens);
void 			shell_execution(t_group *all_token, t_command **all_command);
void 			clean_tokens(t_group *all_token);
void			clean_commands(t_command **all_commands);
#endif