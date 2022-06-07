/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:46:43 by tweimer           #+#    #+#             */
/*   Updated: 2022/06/07 14:50:07 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution/execution.h"

//	During the execution of the here_document we create
//	a temporary file that will next be used as a normal
//	redirection of input and then be deleted
int	execute_here_doc(char *str)
{
	int		tmp_fd;
	char	*content;

	content = NULL;
	tmp_fd = 0;
	tmp_fd = create_temporary_file();
	if (tmp_fd == -1)
	{
		write(2, "error\n", 6);
		return (tmp_fd);
	}
	content = ft_strdup(str);
	ft_putendl_fd(content, tmp_fd);
	free(content);
	return (tmp_fd);
}

// Read form the pipe of the child and transform it into a normal string
char	*get_string(int fd)
{
	int		ret;
	char	*buffer;
	char	tmp[2];

	buffer = NULL;
	while (1)
	{
		ret = read(fd, tmp, 1);
		tmp[ret] = '\0';
		if (ret <= 0)
			break ;
		if (buffer == NULL)
		{
			buffer = ft_strdup(tmp);
		}
		else
		{
			buffer = ft_strjoin_custom(buffer, tmp);
		}
		if (ret <= 0)
			break ;
	}
	return (buffer);
}

void	here_doc_child(int fd, char *delimiter)
{
	char	*input;

	while (1)
	{
		input = readline("> ");
		if (ft_strcmp(input, delimiter) == MATCH)
		{
			close(fd);
			free(input);
			input = NULL;
			break ;
		}
		else
		{
			ft_putendl_fd(input, fd);
		}
		free(input);
		input = NULL;
	}
	exit(0);
}

//	We get the content of the here_document
//	Because we don't want to write in stdin we create a process
//	And to recuperate all the things that the child contain we
//	We need a pipe
char	*get_content(char *delimiter)
{
	int		pid;
	int		status;
	int		pipefd[2];
	char	*rtn;

	pipe(pipefd);
	pid = fork ();
	if (pid == 0)
	{
		signal(SIGINT, signal_here_document);
		close(pipefd[0]);
		here_doc_child(pipefd[1], delimiter);
	}
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	close(pipefd[1]);
	rtn = get_string(pipefd[0]);
	close(pipefd[0]);
	signal(SIGINT, new_prompt);
	return (rtn);
}

//	When the commands are created we create the content of the heredocs
//	and we store them in actual->input->content to use them later
void	handle_here_doc(t_command **all_commands)
{
	t_command	*actual;
	int			i;

	i = 0;
	if (all_commands == NULL || all_commands[0] == NULL)
		return ;
	while (all_commands[i] != NULL)
	{
		actual = all_commands[i];
		if (actual->input != NULL && actual->input->type == DLESS)
		{
			actual->input->content = get_content(actual->input->file_name);
		}
		i++;
	}
}
