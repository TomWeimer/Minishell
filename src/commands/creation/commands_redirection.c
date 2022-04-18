#include "../../../includes/minishell.h"
#include "../../../includes/tokens.h"
#include "../../../includes/syntax.h"
#include "../../../includes/command.h"


t_redirection *init_redirection(void)
{
	t_redirection *new;

	new = malloc(sizeof(t_redirection));
	if (new == NULL)
	{
		write_error(NULL, NULL);
		exit(EXIT_FAILURE);
	}
	new->fd = 0;
	new->file_name = NULL;
	new->next = NULL;
	return (new);
}

void get_redirection_data(t_redirection *first, t_redirection *new, t_token *token)
{
	t_redirection *actual;

	if (first == NULL)
	{
		first = new;
	}
	else
	{
		actual = first;
		while (actual->next != NULL)
		{
			actual = actual->next;
		}
		actual->next = new;
	}
	new->next = NULL;
	new->file_name = ft_strdup(token->next->word);
	new->type = token->type;
}

void add_input(t_command *cmd, t_token *actual_token)
{
	t_redirection *new;

	new = NULL;
	new = init_redirection();
	get_redirection_data(cmd->input, new, actual_token);
	if (cmd->input == NULL)
		cmd->input = new;
}

void add_output(t_command *cmd, t_token *actual_token)
{
	t_redirection *new;

	new = NULL;
	new = init_redirection();
	get_redirection_data(cmd->output, new, actual_token);
	if (cmd->output == NULL)
		cmd->output = new;
}

void create_redirection(t_token *actual, t_command *new_cmd)
{
	while (actual != NULL && token_is_operator(actual->type) == NO)
	{
		if  (actual->type == DLESS || actual->type == LESS)
			add_input(new_cmd, actual);
		else if (actual->type == DGREAT || actual->type == MORE)
		{
			add_output(new_cmd, actual);
			
		}
		actual = actual->next;
	}
}