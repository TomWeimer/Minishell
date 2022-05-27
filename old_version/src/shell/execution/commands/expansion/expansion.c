#include "execution/execution.h"

void	delete_quotes(t_token *actual)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strdup(actual->word);
	free(actual->word);
	actual->word = NULL;
	actual->word = ft_substr(tmp, 1, ft_strlen(tmp) - 2);
	free(tmp);
	tmp = NULL;
}

int	manage_quotes(t_group *token_group)
{
	t_token	*actual;

	actual = token_group->first;
	while (actual != NULL)
	{
		if (actual->word != NULL && is_quote(actual->word[0]) != NONE)
		{
			delete_quotes(actual);
		}
		actual = actual->next;
	}
	return (OK);
}

int	expansion_arguments(t_group *token_group)
{
	if (manage_quotes(token_group) == ERROR)
		return (ERROR);
	return (OK);
}
