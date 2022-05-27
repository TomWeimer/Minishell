/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:44:06 by tweimer           #+#    #+#             */
/*   Updated: 2022/05/27 15:50:41 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution/binary_tree.h"

void	clean_tree(t_tree *node)
{
	if (node == NULL)
		return ;
	clean_tree(node->left);
	clean_tree(node->right);
	free(node);
	node = NULL;
}

void	clean_cmd_redirection(t_redirection *first)
{
	t_redirection	*actual;
	t_redirection	*to_delete;

	to_delete = NULL;
	actual = first;
	while (actual != NULL)
	{
		to_delete = actual;
		actual = actual->next;
		if (to_delete->file_name != NULL)
			free(to_delete->file_name);
		if (to_delete->content != NULL)
			free(to_delete->content);
		free(to_delete);
	}
}

void	clean_cmd_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		args[i] = NULL;
		i++;
	}
}

void	clean_commands(t_command **all_commands)
{
	int	i;

	i = 0;
	if (all_commands != NULL)
	{
		while (all_commands[i] != NULL)
		{
			if (all_commands[i]->args != NULL)
				clean_cmd_args(all_commands[i]->args);
			if (all_commands[i]->input != NULL)
				clean_cmd_redirection(all_commands[i]->input);
			if (all_commands[i]->output != NULL)
				clean_cmd_redirection(all_commands[i]->output);
			free(all_commands[i]);
			all_commands[i] = NULL;
			i++;
		}
	}
}

void	clean_tokens(t_group *all_token)
{
	t_token	*actual;
	t_token	*to_delete;

	if (all_token != NULL)
	{
		to_delete = NULL;
		actual = all_token->first;
		while (actual != NULL)
		{
			to_delete = actual;
			actual = actual->next;
			if (to_delete->word != NULL)
			{
				free(to_delete->word);
				to_delete->word = NULL;
			}
			free(to_delete);
			to_delete = NULL;
		}
	}
}
