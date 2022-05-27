#ifndef BINARY_TREE_H
# define BINARY_TREE_H

// define:
# define RIGHT 1
# define LEFT 2
# include "minishell.h"
// structures
typedef struct s_tree
{
	int					*fd;
	t_token				*token;
	t_command			*cmd;
	struct	s_tree	*previous;
	struct	s_tree	*left;
	struct	s_tree	*right;
}t_tree;

//prototypes
t_tree	*binary_tree(t_group *token_group, t_command **all_command);
void		add_previous_node(t_tree *root, t_tree *previous);
int  		get_nb_operator(t_group *token_group);
t_tree	*new_treenode(void);
void		clean_tree(t_tree *node);
#endif