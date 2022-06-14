/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:44:37 by tweimer           #+#    #+#             */
/*   Updated: 2022/06/13 14:51:17 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// When encountering an error display the error message, and if message_extra
// and/or command are not NULL display them as well.
void	write_error(char *message_extra, char *command, char *erreur_message)
{
	write(STDERR_FILENO, "bash: ", 6);
	if (command != NULL)
		write(STDERR_FILENO, command, ft_strlen(command));
	if (message_extra != NULL)
	{
		write(STDERR_FILENO, message_extra, ft_strlen(message_extra));
		write(STDERR_FILENO, ": ", 2);
	}
	if (erreur_message != NULL)
		write(STDERR_FILENO, erreur_message, ft_strlen(erreur_message));
	else
		perror(NULL);
	write(STDERR_FILENO, NEWLINE, 1);
}

//	When an error is encountered and need to leave the programm
//	or when the user enter exit or CTRL-D. 
//	The shell free all the allocate memmory, to avoid leaks.
void	clean_shell(void)
{
	if (g_data.all_commands != NULL)
		clean_commands(g_data.all_commands);
	if (g_data.all_tokens != NULL)
		clean_tokens(g_data.all_tokens);
	if (g_data.input != NULL)
	{
		free(g_data.input);
		g_data.input = NULL;
	}
	if (g_data.binary_tree != NULL)
		clean_tree(g_data.binary_tree);
	if (g_data.env != NULL)
	{
		clean_env(g_data.env->list);
		if (g_data.env->temp != NULL)
			clean_env(g_data.env->temp);
	}
}

// Display an error message if the tokens are incorrect or in the case if
// the quotes presents aren't in pair.
void	write_syntax_token_error(int token_type)
{
	write(2, "tsh: syntax error near unexpected token ", 40);
	if (token_type == PIPE)
		write(2, "\'|\'\n", 4);
	else if (token_type == OR_IF)
		write(2, "\'||\'\n", 5);
	else if (token_type == AND_IF)
		write(2, "\'&&\'\n", 5);
	else if (token_type == MORE)
		write(2, "\'>\'\n", 4);
	else if (token_type == LESS)
		write(2, "\'<\'\n", 4);
	else if (token_type == DGREAT)
		write(2, "\'>>\'\n", 5);
	else if (token_type == DLESS)
		write(2, "\'<<\'\n", 5);
}
