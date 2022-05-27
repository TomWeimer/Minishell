/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:46:52 by tweimer           #+#    #+#             */
/*   Updated: 2022/05/27 14:11:32 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution/execution.h"
#include "environment/env.h"

void	execute_builtin(t_tree *node, int ok, t_env *env)
{
	replace_input(node->cmd);
	if (ok == CMD_ECHO)
		ft_echo(node->cmd);
	else if (ok == CMD_CD)
		ft_cd(node->cmd, env);
	else if (ok == CMD_PWD)
		ft_pwd(node->cmd);
	else if (ok == CMD_EXIT)
		ft_exit(node->cmd);
	else if (ok == CMD_EXPORT)
		ft_export(env, env->list, node->cmd);
	else if (ok == CMD_UNSET)
		ft_unset(env, node->cmd->args);
	else if (ok == CMD_ENV)
		printenv(node->cmd, env, env->list);
	ft_lastcmd(ok, env);
}

int execute_not_builtin(t_tree *node, t_env *env, int type, int ok)
{
		if (type != PIPE)
			ok = base_builtin(node->cmd->args, env);
		else
			ok = pipe_base_builtin(node, env);
		if (ok == YES) // base builtin executer
		{
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



int	execute_cmd(t_tree *node, t_env *env, int type)
{
	int	ok;
	ok = 0;

	if (node->cmd->args == NULL)
		return (1);
	ft_wildcard(node->cmd);
	ok = ft_checkequal(node->cmd->args, env);
	if (ft_tabchr(node->cmd->args, '$') == 1)
		node->cmd->args = ft_remplaceargs(node->cmd->args, env);
	input_redirection(node->cmd);
	output_redirection(node->cmd);
	ok = is_builtin(node->cmd->args[0]);
	if (ok <= 0)
	{
		return (execute_not_builtin(node, env, type, ok));
	}
	else
	{
		execute_builtin(node, ok, env);
		node->cmd->status = 1;
		dup2(g_data.stdout_fd, STDOUT_FILENO);
		dup2(g_data.stdin_fd, STDIN_FILENO);
		return (1);
	}
}

void	shell_execution(t_group *all_token, t_command **all_command, t_env *env)
{
	t_tree	*root;

	root = binary_tree(all_token, all_command);
	manage_node_execution(root, env);
	clean_tree(root);
	if (root != NULL)
		root = NULL;
}
