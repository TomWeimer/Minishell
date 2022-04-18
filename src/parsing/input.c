#include "../../includes/minishell.h"
#include "../../includes/tokens.h"
#include "../../includes/syntax.h"


char *delete_border_ifs(char *tmp)
{
	int i;
	int j;
	int size;
	char *input;

	input = NULL;
	i = 0;
	size = ft_strlen(tmp) - 1;
	j = size;
	while (tmp[i] != '\0' && is_ifs(tmp[i]) == YES)
		i++;
	while (j > 0 && is_ifs(tmp[j]) == YES)
		j--;
	input = ft_substr(tmp, i, (j - i) + 1);
	free(tmp);
	tmp = NULL;
	return (input);
}


int is_control(char *tmp)
{
	int i;

	i = 0;
	if (tmp == NULL)
		return (NO);
	while (tmp[i])
	{
		if (tmp[i] == '^')
		{
			if (tmp[i + 1] == 92)
				return (YES);
		}
		i++;
	}
	return (NO);
}
char *get_input(void)
{
	char *input;
	char *tmp;

	tmp = NULL;
	input = NULL;
	tmp = readline("prompt $$ ");
	if (tmp == NULL)
	{
		exit(EXIT_SUCCESS);
	}
	add_history(tmp);
	input = delete_border_ifs(tmp);
	return (input);
}