#include "parsing/parsing.h"

char	*delete_border_ifs(char *tmp)
{
	int		i;
	int		j;
	int		size;
	char	*input;

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

char	*get_user_input(void)
{
	char	*input;
	char	*tmp;

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
