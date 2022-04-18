#include "../../../includes/minishell.h"
#include "../../../includes/tokens.h"
#include "../../../includes/syntax.h"
#include "../../../includes/command.h"

t_command *new_command(t_token *actual_token)
{
	t_command *new_cmd;

	new_cmd = NULL;
	new_cmd = init_new_cmd();
	create_redirection(actual_token, new_cmd);
	create_arguments(actual_token, new_cmd);
	return (new_cmd);
}

t_command *get_command(t_group_token *token_group)
{
	static t_token *actual_token = NULL;
	t_command *command;

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

t_command **create_commands(t_group_token *token_group)
{
	t_command **all_commands;
	int nb_commands;
	int i;

	i = 0;
	nb_commands = find_nb_commands(token_group);
	all_commands = init_all_commands(nb_commands);
	while (i < nb_commands)
	{
		all_commands[i] = get_command(token_group);
		i++;
	}
	all_commands[i] = NULL;
	return (all_commands);
}

t_command **shell_commands(t_group_token *all_tokens)
{
	expansion_arguments(all_tokens);
	return (create_commands(all_tokens));
}