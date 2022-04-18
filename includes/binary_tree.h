#ifndef BINARY_TREE_H
# define BINARY_TREE_H
#define RIGHT 1
#define LEFT 2

# include "tokens.h"
# include "command.h"

/* 									STRUCTURES									*/
typedef struct s_treenode
{
	int *fd;
	t_token	*token;
	t_command *cmd;
	struct	s_treenode *previous;
	struct	s_treenode *left;
	struct	s_treenode *right;
}t_treenode;

#endif