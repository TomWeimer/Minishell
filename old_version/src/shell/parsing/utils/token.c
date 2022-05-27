#include "parsing/parsing.h"

int	token_is_redirection(int token_type)
{
	if (token_type == DLESS || token_type == LESS || token_type == DGREAT)
		return (YES);
	else if (token_type == MORE)
		return (YES);
	return (NO);
}

int	token_is_operator(int token_type)
{
	if (token_type == AND_IF || token_type == OR_IF || token_type == PIPE)
		return (YES);
	return (NO);
}
