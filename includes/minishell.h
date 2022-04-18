#ifndef MINISHELL_H
# define MINISHELL_H

#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
# include "../libft/libft.h"
# include "tokens.h"
# include "command.h"
# include "binary_tree.h"
#include <fcntl.h>

# define RUNNING 1
# define END 0
# define CMD_ECHO	1
# define CMD_CD		2
# define CMD_PWD	3
# define CMD_EXIT	4

#define _POSIX_SOURCE
#include <termios.h>

typedef struct termios  t_terminal;
void	rl_replace_line(const char *, int);
void manage_here_doc(t_command **all_commands);
void clean_commands(t_command **all_commands);
void clean_tokens(t_group_token *all_tokens);
void clean_input(char *input);
void print_to_outfiles(char *str, t_command *cmd);
t_group_token *init_all_tokens(void);
int token_attribution(t_group_token *token_group);
void add_new_token(t_token *new_token, t_group_token *all_token);
t_command **init_all_commands(int nb_command);
t_command *init_new_cmd(void);
void create_redirection(t_token *actual, t_command *new_cmd);
void shell_execution(t_group_token *all_token, t_command **all_command);
t_command **shell_commands(t_group_token *all_tokens);
char *get_input(void);
void replace_input(t_command *cmd);
void close_redirection(t_redirection *files);
int redirection_files(t_command *cmd);
void here_doc(t_command *cmd);
void add_previous_node(t_treenode *root, t_treenode *previous);
void redirect_input(int *fd);
void redirect_output(int *fd);
void	ft_pwd(t_command *cmd);
void ft_exit(t_command *cmd);
void	ft_cd(t_command *cmd);
void 	ft_echo(t_command *cmd);
void second_cmd(t_treenode *node, t_treenode *cmd);
void child(t_treenode *main_pipe, t_treenode *sub_node, int side);
void manage_node_execution(t_treenode *root);
void first_cmd(t_treenode *node, t_treenode *cmd);

int execute_cmd(t_treenode *node);

void print2D(t_treenode *root);
int pipe_behaviour(t_treenode *node);
t_treenode *binary_tree(t_group_token *token_group, t_command **all_command);
int  get_nb_operator(t_group_token *token_group);
t_treenode *new_treenode(void);

void create_arguments(t_token *start, t_command *new_cmd);
int get_size_args(t_token *actual);
void add_redirection(t_token *actual, t_command *cmd);
int find_nb_commands(t_group_token *token_group);
void printlst_all_cmd(t_command **all_command);
typedef struct sigaction t_sigaction;
void block_signals_from_keyboard(void);
int	ft_strcmp(const char *s1, const char *s2);
t_group_token *parse_input(char *input);
char	*ft_strjoin_custom(char *s1, char *s2);
int token_is_operator(int token_type);
int token_is_redirection(int token_type);
int token_attribution(t_group_token *token_group);

void printlst_token(t_group_token *list);
void write_syntax_token_error(int token_type);
void write_error(char *message_extra, char *command);
int expansion_arguments(t_group_token *token_group);
int execution(t_group_token *all_token);
t_command **create_list_commands(t_group_token *token_group);

#endif