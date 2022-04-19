#include "execution/execution.h"

t_command	*init_new_cmd(void)
{
	t_command	*cmd;

	cmd = NULL;
	cmd = malloc(sizeof(t_command));
	if (cmd == NULL)
	{
		write_error(NULL, NULL);
		exit(EXIT_FAILURE);
	}
	cmd->args = NULL;
	cmd->input = NULL;
	cmd->output = NULL;
	cmd->next = NULL;
	cmd->cmd = NULL;
	return (cmd);
}

t_command	**init_all_commands(int nb_command)
{
	t_command	**all_cmd;

	all_cmd = NULL;
	all_cmd = malloc(sizeof(t_command *) * (nb_command + 1));
	if (all_cmd == NULL)
	{
		write_error(NULL, NULL);
		exit(EXIT_FAILURE);
	}
	return (all_cmd);
}

int	find_nb_commands(t_group *token_group)
{
	t_token	*actual;
	int		nb;

	nb = 1;
	if (token_group == NULL || token_group->first == NULL)
		return (0);
	actual = token_group->first;
	while (actual != NULL)
	{
		if (token_is_operator(actual->type))
			nb++;
		actual = actual->next;
	}
	return (nb);
}
