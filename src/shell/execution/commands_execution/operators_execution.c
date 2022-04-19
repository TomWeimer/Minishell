#include "execution/execution.h"

int	pipe_behaviour(t_tree *node)
{
	int	pid[2];
	int	status[2];

	node->fd = malloc(sizeof(int) * 2);
	pipe(node->fd);
	pid[0] = fork();
	if (pid[0] == 0)
	{
		child(node, node->left, LEFT);
		exit(1);
	}
	waitpid(pid[0], &status[0], 0);
	pid[1] = fork();
	if (pid[1] == 0)
	{
		child(node, node->right, RIGHT);
		exit(1);
	}
	waitpid(pid[1], &status[1], 0);
	return (1);
}

void	and_if_behaviour(t_tree *node)
{
	execute_cmd(node->left);
	if (node->left->cmd->status == 1)
	{
		if (node->right != NULL && node->right->cmd != NULL)
		{
			execute_cmd(node->right);
		}
		else if (node->right != NULL)
			manage_node_execution(node->right);
	}
}

void	or_if_behaviour(t_tree *node)
{
	execute_cmd(node->left);
	if (node->left->cmd->status == 0)
	{
		if (node->right != NULL && node->right->cmd != NULL)
		{
			execute_cmd(node->right);
		}
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
	{
		execute_cmd(root);
	}
}
