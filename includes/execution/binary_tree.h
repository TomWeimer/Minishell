/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:47:46 by tchappui          #+#    #+#             */
/*   Updated: 2022/06/06 14:55:26 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H
# define BINARY_TREE_H

// define:
# define RIGHT 1
# define LEFT 2
# include "execution/command.h"
# include  "parsing/tokens.h"
// structures
typedef struct s_tree
{
	int					*fd;
	t_token				*token;
	t_command			*cmd;
	struct s_tree		*previous;
	struct s_tree		*left;
	struct s_tree		*right;
}t_tree;

//prototypes
t_tree		*binary_tree(t_group *token_group, t_command **all_command);
void		add_previous_node(t_tree *root, t_tree *previous);
int			get_nb_operator(t_group *token_group);
t_tree		*new_treenode(void);
void		clean_tree(t_tree *node);
#endif