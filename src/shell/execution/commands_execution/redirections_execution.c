#include "execution/execution.h"

void	replace_input(t_command *cmd)
{
	t_redirection	*actual;

	if (cmd->input == NULL)
		return ;
	actual = cmd->input;
	while (actual->next != NULL)
	{
		if (actual->type == LESS)
		{
			actual->fd = open(actual->file_name, O_RDONLY);
			dup2(actual->fd, STDIN_FILENO);
			close(actual->fd);
		}
		actual = actual->next;
	}
}

int	redirection_files(t_command *cmd)
{
	t_redirection	*actual;
	t_redirection	*last;

	last = NULL;
	actual = NULL;
	if (cmd->output == NULL)
		return (0);
	actual = cmd->output;
	while (actual != NULL)
	{
		last = actual;
		actual = actual->next;
	}
	if (last->type == DGREAT)
	{
		last->fd = open(last->file_name, O_WRONLY | O_CREAT
				| O_APPEND, S_IWUSR | S_IRUSR);
	}
	else if (last->type == MORE)
	{
		last->fd = open(last->file_name, O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR);
	}
	return (1);
}

void	exec_here_doc(char *key)
{
	char	*str;

	str = NULL;
	while (ft_strcmp(key, str) != 0)
	{
		if (str != NULL)
		{
			free(str);
			str = NULL;
		}
		str = readline("heredoc> ");
	}
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
}

void	here_doc(t_command *cmd)
{
	t_redirection	*actual;

	if (cmd->input == NULL)
		return ;
	actual = cmd->input;
	while (actual != NULL)
	{
		if (actual->type == DLESS)
		{
			exec_here_doc(actual->file_name);
		}
		actual = actual->next;
	}
}

void	manage_here_doc(t_command **all_commands)
{
	int	i;

	i = 0;
	if (all_commands == NULL)
		return ;
	while (all_commands[i] != NULL)
	{
		here_doc(all_commands[i]);
		i++;
	}
}
