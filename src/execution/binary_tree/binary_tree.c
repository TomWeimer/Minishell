#include "../../../includes/syntax.h"
#include "../../../includes/tokens.h"
#include "../../../includes/command.h"
#include "../../../includes/minishell.h"
#include "../../../includes/binary_tree.h"

t_treenode *node_cmd(t_treenode *node, int actual_cmd, t_command **all_command)
{
	t_treenode *new;

	(void)node;
	if (all_command == NULL || all_command[0] == NULL)
		return (NULL);
	new = new_treenode();
	new->token = NULL;
	new->cmd = all_command[actual_cmd];
	new->left = NULL;
	new->right = NULL;

	return (new);
}

t_token *get_next_operator(t_group_token *token_group, int actual_op, int max_op)
{
	t_token *actual;
	int i;
	static int  nb_operator = 1;

	if (nb_operator == -1)
		nb_operator = 1;
	i = 0;
	actual = token_group->first;
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

t_treenode *new_treenode(void)
{
	t_treenode *new;

	new = malloc(sizeof(t_treenode));
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

t_treenode *construct_tree(t_group_token *token_group, t_command **all_command, int max_operator, int actual_operator)
{
	t_treenode	*node;
	t_token		*actual;

	node = NULL;
	
	actual = get_next_operator(token_group, actual_operator, max_operator);
	if (actual_operator <= max_operator)
	{
		node = new_treenode();
		node->token = actual;
		node->cmd = NULL;
		if (actual_operator != max_operator)
		{
			node->left = node_cmd(node, actual_operator, all_command);
			node->right = construct_tree(token_group, all_command, max_operator,  actual_operator + 1);
		}
		else
		{
			node->left = node_cmd(node, actual_operator, all_command);
			node->right = node_cmd(node, actual_operator + 1, all_command);
		}
	}
	return (node);
}

t_treenode *binary_tree(t_group_token *token_group, t_command **all_command)
{
	t_treenode *root;
	int nb_operator;

	root = NULL;
	nb_operator = get_nb_operator(token_group);
	if (nb_operator == 0)
	{
		root = node_cmd(NULL, 0, all_command);
	}
	else
	{
		root = construct_tree(token_group, all_command, nb_operator - 1, 0);
		add_previous_node(root, NULL);
	}
	return(root);
}