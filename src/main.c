#include "../includes/minishell.h"
#include "../includes/tokens.h"
#include "../includes/syntax.h"

int manage_commands(t_group_token *all_tokens)//env
{
	t_command **all_commands;

	all_commands = shell_commands(all_tokens);//env
	shell_execution(all_tokens, all_commands);
	if (all_commands != NULL)
	{
		clean_commands(all_commands);
		all_commands = NULL;
	}
	return (1);
}

void manage_tokens(char *input)//env
{
	t_group_token *all_tokens;

	all_tokens = tokenizer(input);
	manage_commands(all_tokens);//env
	if (all_tokens != NULL)
	{
		clean_tokens(all_tokens);
		free(all_tokens);
		all_tokens = NULL;
	}
}

void manage_user_input(void)//env
{
	char *input;

	input = get_input();
	manage_tokens(input);//env
	free(input);
	input = NULL;
}

int main(int argc , char *argv[])
{
	char	*input;
	t_terminal config;
	int rc;

	(void)argv;
	if (argc > 1 || argc < 1)
		return (0);
	//create_env
	rc = tcgetattr(STDIN_FILENO, &config);
	config.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, rc, &config);
	input = NULL;
	block_signals_from_keyboard();
	while (RUNNING)
	{
		manage_user_input(/*env*/);
	//	write(2, "\nnp\n", 4);
	}
	return (1);
}