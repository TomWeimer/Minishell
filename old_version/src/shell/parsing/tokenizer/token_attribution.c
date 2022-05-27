#include "parsing/parsing.h"

t_token	*find_start_cmd(t_token *end, t_group *all_tokens)
{
	t_token	*actual;

	actual = NULL;
	if (all_tokens == NULL)
		return (NULL);
	if (end == NULL)
		actual = all_tokens->first;
	else
		actual = end->next;
	while (actual != NULL && token_is_operator(actual->type) == YES)
		actual = actual->next;
	return (actual);
}

t_token	*find_end_cmd(t_token *start, t_group *all_tokens)
{
	t_token	*actual;

	if (all_tokens == NULL || start == NULL)
		return (NULL);
	actual = start;
	while (actual != NULL && token_is_operator(actual->type) == NO)
		actual = actual->next;
	return (actual);
}

int	attribute_redirection(t_token *actual)
{
	if (actual->next == NULL || actual->next->type != WORD)
	{
		write_syntax_token_error(actual->type);
		return (ERROR);
	}
	if (actual->type == MORE || actual->type == DGREAT)
		actual->next->type = OUTFILE;
	else if (actual->type == LESS || actual->type == DLESS)
		actual->next->type = INFILE;
	return (OK);
}

int	attribute_token(t_token *start, t_token *end)
{
	int		cmd;
	t_token	*actual;

	if (start == NULL)
		return (OK);
	actual = start;
	while (actual != NULL && actual != end)
	{
		if (token_is_redirection(actual->type) == YES)
		{
			if (attribute_redirection(actual) == ERROR)
				return (ERROR);
			actual = actual->next;
		}
		else if (cmd == NONE)
		{
			actual->type = CMD;
			cmd = OK;
		}
		else
			actual->type = PARAM;
		actual = actual->next;
	}
	return (OK);
}

int	token_attribution(t_group *token_group)
{
	int		loop;
	t_token	*start;
	t_token	*end;

	loop = START;
	end = NULL;
	while (loop != STOP)
	{
		start = find_start_cmd(end, token_group);
		end = find_end_cmd(start, token_group);
		if (attribute_token(start, end) == ERROR)
			return (ERROR);
		if (end == NULL)
			loop = STOP;
	}
	return (OK);
}
