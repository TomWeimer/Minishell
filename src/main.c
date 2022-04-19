#include "minishell.h"
#include "execution/command.h"

int	manage_commands(t_group *all_tokens)
{
	t_command	**all_commands;

	all_commands = shell_commands(all_tokens);
	shell_execution(all_tokens, all_commands);
	if (all_commands != NULL)
	{
		clean_commands(all_commands);
		all_commands = NULL;
	}
	return (1);
}

void	manage_tokens(char *input)
{
	t_group	*all_tokens;

	all_tokens = tokenizer(input);
	manage_commands(all_tokens);
	if (all_tokens != NULL)
	{
		clean_tokens(all_tokens);
		free(all_tokens);
		all_tokens = NULL;
	}
}

void	manage_user_input(void)
{
	char	*input;

	input = get_user_input();
	manage_tokens(input);
	free(input);
	input = NULL;
}

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc == 1)
	{
		init_terminal();
		while (RUNNING)
		{
			manage_user_input();
		}
		return (1);
	}
	return (0);
}
