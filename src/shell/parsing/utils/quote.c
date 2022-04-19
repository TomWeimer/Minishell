#include "parsing/parsing.h"

int	is_quote(char c)
{
	int	i;

	i = 0;
	if (c == '\'')
		return (SQUOTED);
	else if (c == '\"')
		return (DQUOTED);
	return (NONE);
}

int	is_quoted(char *input, int start_token, int i)
{
	int	start_quote;
	int	end_quote;

	if (start_token == i)
		return (NO);
	start_quote = is_quote(input[start_token]);
	end_quote = is_quote(input[i]);
	if (start_quote != NONE && start_quote == end_quote)
		return (ENDED);
	if (start_quote == NONE && end_quote == NONE)
		return (NO);
	return (YES);
}
