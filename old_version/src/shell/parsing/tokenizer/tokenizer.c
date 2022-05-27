#include "parsing/parsing.h"

t_token	*init_token(char *input, int start)
{
	t_token	*new_token;
	int		token_type;

	new_token = malloc(sizeof(t_token));
	if (new_token == NULL)
	{
		write(2, MALLOC_ERROR, 35);
		exit(EXIT_FAILURE);
	}
	token_type = is_special(input, start);
	if (token_type != NONE)
		new_token->type = token_type;
	else
		new_token->type = WORD;
	new_token->word = NULL;
	return (new_token);
}

t_token	*create_token(char *input, int start, int end)
{
	t_token	*token;

	token = init_token(input, start);
	if (token->type == WORD)
		token->word = ft_substr(input, start, end - start);
	return (token);
}

t_token	*get_token(char *input)
{
	int			i;
	t_token		*token;
	static int	start_token = 0;

	if (no_more_token(start_token, input) == YES)
	{
		start_token = 0;
		return (NULL);
	}
	token = NULL;
	i = start_token;
	while (input[i] != '\0' && token == NULL)
	{
		if (token_ended(input, start_token, i))
			token = create_token(input, start_token, i + 1);
		i++;
	}
	if (input[i] == '\0' && token == NULL)
		token = create_token(input, start_token, i);
	start_token = find_next_start_token(input, i, token->type);
	return (token);
}

void	generate_tokens(char *input, t_group *all_tokens)
{
	int		looping;
	t_token	*new_token;

	looping = START;
	while (looping != STOP)
	{
		new_token = get_token(input);
		add_new_token(new_token, all_tokens);
		if (new_token == NULL)
			looping = STOP;
	}
}

t_group	*tokenizer(char *input)
{
	t_group	*all_tokens;

	all_tokens = init_all_tokens();
	generate_tokens(input, all_tokens);
	if (all_tokens != NULL && check_token_quote(all_tokens) == ERROR)
	{
		return (NULL);
	}
	token_attribution(all_tokens);
	return (all_tokens);
}
