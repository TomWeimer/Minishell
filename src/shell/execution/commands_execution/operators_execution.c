/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_execution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:46:34 by tweimer           #+#    #+#             */
/*   Updated: 2022/05/27 16:10:15 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution/execution.h"

int	pipe_behaviour(t_tree *node, t_env *env)
{
	int	pid[2];
	int	status;

	node->fd = malloc(sizeof(int) * 2);
	pipe(node->fd);
	signal(SIGINT, no_prompt);
	pid[0] = fork();
	if (pid[0] == 0)
	{
		child(node, node->left, LEFT, env);
		exit(1);
	}
	else 
	{
		g_data.last_pid = pid[0];
		//waitpid(-1,0, 0);
        close(node->fd[1]);
	}
	pid[1] = fork();
	if (pid[1] == 0)
	{
		child(node, node->right, RIGHT, env);
		exit(1);
	}
	g_data.last_pid = pid[1];
	waitpid(g_data.last_pid, &status, 0);
	close(node->fd[0]);
	close(node->fd[1]);
	signal(SIGINT, new_prompt);
	return (1);
}


void	and_if_behaviour(t_tree *node, t_env *env)
{
	execute_cmd(node->left, env, NONE);
	if (node->left->cmd->status == 1)
	{
		if (node->right != NULL && node->right->cmd != NULL)
		{
			execute_cmd(node->right, env, NONE);
		}
		else if (node->right != NULL)
			manage_node_execution(node->right, env);
	}
}

void	or_if_behaviour(t_tree *node, t_env *env)
{
	execute_cmd(node->left, env, NONE);
	if (node->left->cmd->status == 0)
	{
		if (node->right != NULL && node->right->cmd != NULL)
		{
			execute_cmd(node->right, env, NONE);
		}
		else if (node->right != NULL)
			manage_node_execution(node->right, env);
	}
}

void	manage_node_execution(t_tree *root, t_env *env)
{
	t_tree	*actual;

	if (root == NULL)
		return ;
	actual = root;
	if (actual->token != NULL)
	{
		if (actual->token->type == PIPE)
			pipe_behaviour(actual, env);
		else if (actual->token->type == AND_IF)
			and_if_behaviour(actual, env);
		else if (actual->token->type == OR_IF)
			or_if_behaviour(actual, env);
	}
	else
	{
		execute_cmd(root, env, NONE);
	}
}
