/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:45:16 by tweimer           #+#    #+#             */
/*   Updated: 2022/06/07 14:23:37 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution/execution.h"

char	**init_args(int size)
{
	char	**new;

	new = malloc(sizeof(char *) * (size + 1));
	if (new == NULL)
	{
		write_error(NULL, NULL, NULL);
		exit (EXIT_FAILURE);
	}
	return (new);
}

int	get_size_args(t_token *start)
{
	int		size;
	t_token	*actual;

	size = 0;
	actual = start;
	while (actual != NULL && token_is_operator(actual->type) == NO)
	{
		if (actual->type == CMD || actual->type == PARAM)
			size++;
		actual = actual->next;
	}
	return (size);
}

char	**new_args(t_token *actual, int size)
{
	int		i;
	char	**args;

	i = 0;
	args = init_args(size);
	while (actual != NULL && i < size)
	{
		if (actual->type == CMD || actual->type == PARAM)
		{
			args[i] = ft_strdup(actual->word);
			i++;
		}
		actual = actual->next;
	}
	args[i] = NULL;
	return (args);
}

// create new_cmd->args that contain the commands and the command's parameters
void	create_arguments(t_token *start, t_command *new_cmd)
{
	int	size;

	new_cmd->args = NULL;
	size = get_size_args(start);
	if (size != 0)
		new_cmd->args = new_args(start, size);
}
