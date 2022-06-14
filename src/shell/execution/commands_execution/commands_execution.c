/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:46:52 by tweimer           #+#    #+#             */
/*   Updated: 2022/06/14 14:41:00 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution/execution.h"
#include "environment/env.h"

// check which builtin it is then execute the right function
void	execute_builtin(t_tree *node, int ok)
{
	replace_input(node->cmd);
	if (ok == CMD_ECHO)
		ft_echo(node->cmd);
	else if (ok == CMD_CD)
		ft_cd(node->cmd, g_data.env);
	else if (ok == CMD_PWD)
		ft_pwd(node->cmd);
	else if (ok == CMD_EXIT)
	{
		if (node != NULL && node->previous != NULL
			&& node->previous->token != NULL
			&& node->previous->token->type == PIPE)
			ft_exit(node->cmd, NO);
		else
			ft_exit(node->cmd, OK);
	}
	else if (ok == CMD_EXPORT)
		ft_export(g_data.env, g_data.env->list, node->cmd);
	else if (ok == CMD_UNSET)
		ft_unset(g_data.env, node->cmd->args);
	else if (ok == CMD_ENV)
		printenv(g_data.env->list);
	ft_lastcmd(ok);
}

//  The command is not builtin so we check if the type is a pipe or no
//	and call the right function
int	execute_not_builtin(t_tree *node, int type, int ok)
{
	if (type != PIPE)
		ok = base_builtin(node->cmd->args);
	else
		ok = pipe_base_builtin(node);
	if (ok == YES)
	{
		g_data.exit_status = 127;
		node->cmd->status = 1;
		dup2(g_data.stdin_fd, STDIN_FILENO);
		dup2(g_data.stdout_fd, STDOUT_FILENO);
		return (1);
	}
	else
	{
		node->cmd->status = 0;
		dup2(g_data.stdin_fd, STDIN_FILENO);
		dup2(g_data.stdout_fd, STDOUT_FILENO);
		return (0);
	}
}

//	the operators have been "executed" so now
//	1. we execute the redirections
//	2. if the command is a builtin execute_builtin()
//	3.if the command is not a builtin execute_not_builtin()
int	execute_cmd(t_tree *node, int type)
{
	int	ok;

	ok = 0;
	if (node->cmd->args == NULL)
		return (1);
	ok = ft_checkequal(node->cmd->args);
	input_redirection(node->cmd);
	output_redirection(node->cmd);
	if (ok == 0)
		ok = is_builtin(node->cmd->args[0]);
	if (ok <= 0)
		return (execute_not_builtin(node, type, ok));
	else if (ok < 9)
	{
		execute_builtin(node, ok);
		node->cmd->status = 1;
		dup2(g_data.stdout_fd, STDOUT_FILENO);
		dup2(g_data.stdin_fd, STDIN_FILENO);
		return (1);
	}
	return (1);
}

// the commands are now regroup together with the help of a binary tree
// We will execute the commands.
void	shell_execution(t_group *all_token, t_command **all_command)
{
	t_tree	*root;

	if (all_command == NULL)
		return ;
	root = binary_tree(all_token, all_command);
	g_data.binary_tree = root;
	manage_node_execution(root);
	clean_tree(root);
	if (root != NULL)
		root = NULL;
}
