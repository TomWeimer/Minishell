#include "execution/execution.h"

t_tree	*node_cmd(int actual_cmd, t_command **all_command)
{
	t_tree	*new;

	if (all_command == NULL || all_command[0] == NULL)
		return (NULL);
	new = new_treenode();
	new->token = NULL;
	new->cmd = all_command[actual_cmd];
	new->left = NULL;
	new->right = NULL;
	return (new);
}

t_token	*get_next_operator(t_group *all_tokens, int actual_op, int max_op)
{
	t_token		*actual;
	int			i;
	static int	nb_operator = 1;

	if (nb_operator == -1)
		nb_operator = 1;
	i = 0;
	actual = all_tokens->first;
	while (actual->next != NULL && i < nb_operator)
	{
		if (token_is_operator(actual->type) == YES)
			i++;
		if (i < nb_operator)
			actual = actual->next;
	}
	if (actual_op == max_op)
		nb_operator = -1;
	else
		nb_operator++;
	return (actual);
}

t_tree	*new_treenode(void)
{
	t_tree	*new;

	new = malloc(sizeof(t_tree));
	if (new == NULL)
	{
		write_error(NULL, NULL);
		exit (EXIT_FAILURE);
	}
	new->cmd = NULL;
	new->fd = NULL;
	new->left = NULL;
	new->right = NULL;
	new->previous = NULL;
	new->token = NULL;
	return (new);
}

t_tree	*build_tree(t_group *tokens, t_command **commands, int max_op, int op)
{
	t_tree	*node;
	t_token	*actual;

	node = NULL;
	actual = get_next_operator(tokens, op, max_op);
	if (op <= max_op)
	{
		node = new_treenode();
		node->token = actual;
		node->cmd = NULL;
		if (op != max_op)
		{
			node->left = node_cmd(op, commands);
			node->right = build_tree(tokens, commands, max_op, op + 1);
		}
		else
		{
			node->left = node_cmd(op, commands);
			node->right = node_cmd(op + 1, commands);
		}
	}
	return (node);
}

t_tree	*binary_tree(t_group *all_tokens, t_command **all_command)
{
	t_tree	*root;
	int		nb_operator;

	root = NULL;
	nb_operator = get_nb_operator(all_tokens);
	if (nb_operator == 0)
	{
		root = node_cmd(0, all_command);
	}
	else
	{
		root = build_tree(all_tokens, all_command, nb_operator - 1, 0);
		add_previous_node(root, NULL);
	}
	return (root);
}
