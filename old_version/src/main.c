#include "minishell.h"
#include "execution/command.h"
#include "environment/env.h"


int	manage_commands(t_group *all_tokens, t_env *env)
{
	t_command	**all_commands;

	all_commands = shell_commands(all_tokens);
	shell_execution(all_tokens, all_commands, env);
	if (all_commands != NULL)
	{
		clean_commands(all_commands);
		all_commands = NULL;
	}
	return (1);
}

void	manage_tokens(char *input, t_env *env)
{
	t_group	*all_tokens;

	all_tokens = tokenizer(input);
	if (all_tokens != NULL)
		manage_commands(all_tokens, env);
	if (all_tokens != NULL)
	{
		clean_tokens(all_tokens);
		free(all_tokens);
		all_tokens = NULL;
	}
}

void	manage_user_input(t_env *env)
{
	char	*input;

	input = get_user_input();
	manage_tokens(input, env);
	free(input);
	input = NULL;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_env	env;

	
	(void)argv;
	if (argc == 1)
	{
		env.list = NULL;
		env.temp = NULL;
		ft_env(&env.list, envp);
		init_terminal();
		while (RUNNING)
		{
			manage_user_input(&env);
		}
		return (1);
	}
	return (0);
}
/*
void	manage_user_input_test(t_env *env, char *input)
{
	//char	*input;

	//input = get_user_input();
	manage_tokens(input, env);
	//free(input);
	//input = NULL;
}

int launch(char *input, t_env *env)
{
	manage_user_input_test(env, input);
	return (1);
}

int main(int argc, char **argv, char *envp[])
{
  	t_env	env;

	env.list = NULL;
	env.temp = NULL;
	g_envp = envp;
	if (argc == 1)
	{
		ft_env(&env.list, envp);
		init_terminal();
		while (RUNNING)
		{
			manage_user_input(&env);
		}
		return (1);
	}
  else if (argc >= 3 && !ft_strncmp(argv[1], "-c", 3))
	{
			ft_env(&env.list, envp);
			init_terminal();
			launch(argv[2], &env);
			exit(0);
	}
  return (0);
  }
*/