/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:44:20 by tchappui          #+#    #+#             */
/*   Updated: 2022/06/06 14:56:39 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// librairies:
# include <stdio.h>
# include <signal.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>

// headers:
# include	"libft.h"
# include	"parsing/tokens.h"
# include	"execution/command.h"
# include	"execution/binary_tree.h"
# include	"sub_system/error.h"
# include	"environment/env.h"

// define:
typedef struct here_doc
{
	int				id;
	char			*content;
	struct here_doc	*next;
}t_here_doc;

struct s_data
{
	pid_t			pid;
	int				exit_status;
	int				stdin_fd;
	int				stdout_fd;
	t_here_doc		*here_doc;
	int				last_pid;
	t_env			*env;
	char			*input;
	t_group			*all_tokens;
	t_command		**all_commands;
	t_tree			*binary_tree;
}g_data;

# define RUNNING 1
# define IN 0
# define OUT 1
# define TMP_FILE	"/tmp/minishell_temporary_file"
// prototypes:
int			create_temporary_file(void);
void		clean_shell(void);
void		clean_tree(t_tree *node);
void		input_redirection(t_command *cmd);
void		output_redirection(t_command *cmd);
int			ft_checkequal(char **args);
int			is_builtin(char *str);
void		reap_child(int sig);
void		clear_here_doc(void);
void		signal_here_document(int signal);
void		handle_here_doc(t_command **all_commands);
int			execute_here_doc(char *str);
void		no_prompt(int sig);
void		new_prompt(int sig);
void		handler_child(int sig);
void		ft_wildcard(t_command *cmd);
char		*ft_asterix(void);
void		init_terminal(void);
char		*get_user_input(void);
t_group		*tokenizer(char *input);
t_command	**shell_commands(t_group *all_tokens);
void		shell_execution(t_group *all_token, t_command **all_command);
void		clean_tokens(t_group *all_token);
void		clean_commands(t_command **all_commands);
void		exec_signals(void);
#endif