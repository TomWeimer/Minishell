/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:45:38 by tweimer           #+#    #+#             */
/*   Updated: 2022/06/07 14:07:40 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution/execution.h"

t_command	*new_command(t_token *actual_token)
{
	t_command	*new_cmd;

	new_cmd = NULL;
	new_cmd = init_new_cmd();
	create_redirection(actual_token, new_cmd);
	create_arguments(actual_token, new_cmd);
	return (new_cmd);
}

t_command	*get_command(t_group *token_group)
{
	static t_token	*actual_token = NULL;
	t_command		*command;

	command = NULL;
	if (token_group == NULL)
		return (NULL);
	if (actual_token == NULL)
		actual_token = token_group->first;
	command = new_command(actual_token);
	while (actual_token != NULL && token_is_operator(actual_token->type) == NO)
		actual_token = actual_token->next;
	if (actual_token != NULL && actual_token->next != NULL)
		actual_token = actual_token->next;
	return (command);
}

t_command	**create_commands(t_group *token_group)
{
	t_command	**all_commands;
	int			nb_commands;
	int			i;

	i = 0;
	nb_commands = find_nb_commands(token_group);
	all_commands = init_all_commands(nb_commands);
	while (i < nb_commands)
	{
		all_commands[i] = get_command(token_group);
		i++;
	}
	all_commands[i] = NULL;
	handle_here_doc(all_commands);
	g_data.all_commands = all_commands;
	return (all_commands);
}

// Now that the token contain their roles we need to put them together 
//	in commands separated by operators
t_command	**shell_commands(t_group *all_tokens)
{
	expansion_arguments(all_tokens);
	return (create_commands(all_tokens));
}
