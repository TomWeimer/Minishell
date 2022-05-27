/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:47:04 by tweimer           #+#    #+#             */
/*   Updated: 2022/05/27 13:47:05 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution/execution.h"

int	get_nb_operator(t_group *token_group)
{
	t_token	*actual;
	int		nb;

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

void	add_previous_node(t_tree *root, t_tree *previous)
{
	if (root == NULL)
		return ;
	add_previous_node(root->right, root);
	root->previous = previous;
}
