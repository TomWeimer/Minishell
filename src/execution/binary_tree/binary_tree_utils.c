#include "../../../includes/syntax.h"
#include "../../../includes/tokens.h"
#include "../../../includes/command.h"
#include "../../../includes/minishell.h"
#include "../../../includes/binary_tree.h"


int  get_nb_operator(t_group_token *token_group)
{
	t_token *actual;
	int nb;

	nb = 0;
	actual = token_group->first;
	while (actual != NULL)
	{
		if (token_is_operator(actual->type) == YES)
			nb++;
		actual = actual->next;
	}
	return (nb);
}

void add_previous_node(t_treenode *root, t_treenode *previous)
{

	if (root == NULL)
		return ;
	add_previous_node(root->right, root);
	root->previous = previous;
	
}
