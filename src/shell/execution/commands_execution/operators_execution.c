/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_execution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:46:34 by tweimer           #+#    #+#             */
/*   Updated: 2022/06/14 13:57:38 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution/execution.h"

void	first_pipe(int *pid, t_tree *node)
{
	if (pid[0] == 0)
	{
		child(node, node->left, LEFT);
		exit(1);
	}
	else
	{
		g_data.last_pid = pid[0];
		close(node->fd[1]);
	}
}

int	pipe_behaviour(t_tree *node)
{
	int	pid[2];
	int	status;

	node->fd = malloc(sizeof(int) * 2);
	pipe(node->fd);
	signal(SIGINT, SIG_IGN);
	pid[0] = fork();
	first_pipe(pid, node);
	pid[1] = fork();
	if (pid[1] == 0)
	{
		child(node, node->right, RIGHT);
		exit(1);
	}
	g_data.last_pid = pid[1];
	waitpid(g_data.last_pid, &status, 0);
	close(node->fd[0]);
	close(node->fd[1]);
	return (1);
}

void	and_if_behaviour(t_tree *node)
{
	execute_cmd(node->left, NONE);
	if (node->left->cmd->status == 1)
	{
		if (node->right != NULL && node->right->cmd != NULL)
			execute_cmd(node->right, NONE);
		else if (node->right != NULL)
			manage_node_execution(node->right);
	}
}

void	or_if_behaviour(t_tree *node)
{
	execute_cmd(node->left, NONE);
	if (node->left->cmd->status == 0)
	{
		if (node->right != NULL && node->right->cmd != NULL)
			execute_cmd(node->right, NONE);
		else if (node->right != NULL)
			manage_node_execution(node->right);
	}
}

void	manage_node_execution(t_tree *root)
{
	t_tree	*actual;

	if (root == NULL)
		return ;
	actual = root;
	if (actual->token != NULL)
	{
		if (actual->token->type == PIPE)
			pipe_behaviour(actual);
		else if (actual->token->type == AND_IF)
			and_if_behaviour(actual);
		else if (actual->token->type == OR_IF)
			or_if_behaviour(actual);
	}
	else
		execute_cmd(root, NONE);
}
