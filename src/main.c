/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:32:32 by tchappui          #+#    #+#             */
/*   Updated: 2022/06/14 13:22:51 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution/command.h"
#include "environment/env.h"

//	1. Receive the tokens and assemble them into different commands.
//	2. Begin to execute the commands
//	3. The commands were executed they aren't needed anymore
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

// Receive the input (the instructions) from the previous function
// 1.	Parse the input and transform them into tokens,
//		to see more about tokens go to "tokens.h"
// 2.	If tokens were created by the previous step go to the
//		next step, before the execution of the input
// 3.	The tokens are no longer needed it's time to free them
void	manage_tokens(char *input)
{
	t_group	*all_tokens;

	all_tokens = tokenizer(input);
	if (all_tokens != NULL)
		manage_commands(all_tokens);
	if (all_tokens != NULL)
	{
		clean_tokens(all_tokens);
		free(all_tokens);
		all_tokens = NULL;
	}
}

// While the shell is running the shell wait instructions
// 1. get (the instructions), input.
// 2. analyze and execute the (instructions) input.
// 3. Free the old instructions, to make place for the new ones
void	manage_user_input(void)
{
	char	*input;

	input = get_user_input();
	if (input != NULL)
	{
		manage_tokens(input);
		free(input);
		input = NULL;
	}
}

// If the number of argument is correct, launch the shell.
// 1. Create the environement of the shell
// 2. Initialize all the necessary parameter of the shell
// 3. The shell is ready to receive input from the user
int	main(int argc, char *argv[], char *envp[])
{
	t_env	env;

	(void)argv;
	if (argc == 1)
	{
		env.list = NULL;
		env.temp = NULL;
		ft_env(&env.list, envp);
		g_data.env = &env;
		init_terminal();
		while (RUNNING)
		{
			manage_user_input();
		}
		return (1);
	}
	return (0);
}
