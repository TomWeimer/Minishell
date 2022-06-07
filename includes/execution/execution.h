/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:49:15 by tchappui          #+#    #+#             */
/*   Updated: 2022/06/05 21:49:38 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

//librairies
# include <fcntl.h>
# include <readline/readline.h>
// headers:
# include "minishell.h"
# include "execution/binary_tree.h"
# include "execution/execution.h"

// define:
# define NO 0
# define YES 1
# define ERROR 0
# define OK 1
# define CMD_ECHO	1
# define CMD_CD		2
# define CMD_PWD	3
# define CMD_EXIT	4
# define CMD_EXPORT	5
# define CMD_UNSET	6
# define CMD_ENV	7

// prototypes:
t_command	*init_new_cmd(void);
t_command	**init_all_commands(int nb_command);
int			find_nb_commands(t_group *token_group);
void		create_arguments(t_token *start, t_command *new_cmd);
void		create_redirection(t_token *actual, t_command *new_cmd);
int			expansion_arguments(t_group *token_group);
int			is_quote(char c);
int			token_is_operator(int token_type);
int			token_is_redirection(int token_type);
void		redirect_input(int *fd);
void		redirect_output(int *fd);
void		replace_input(t_command *cmd);
int			redirection_files(t_command *cmd);
void		manage_here_doc(t_command **all_commands);
void		manage_node_execution(t_tree *root);
void		child(t_tree *main_pipe, t_tree *sub_node, int side);
int			execute_cmd(t_tree *node, int type);
void		ft_pwd(t_command *cmd);
void		ft_exit(t_command *cmd);
void		ft_cd(t_command *cmd, t_env *env);
void		ft_echo(t_command *cmd);
int			base_builtin(char **str);
void		ft_lastcmd(int ok);
int			pipe_base_builtin(t_tree *node);
char		*replace_dollar(char *args, t_env *env, int exit_s);
char		*find_path(t_list *list, char *arg);

#endif