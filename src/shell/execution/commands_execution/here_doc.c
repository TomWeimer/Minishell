/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:46:43 by tweimer           #+#    #+#             */
/*   Updated: 2022/05/27 15:58:48 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution/execution.h"


int	create_temporary_file(void)
{
	int	fd;

	fd = open(TMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		write_error(NULL, NULL);
	return (fd);
}

char *pop_here_doc(void)
{
	t_here_doc	*tmp;
	char		*content;

	tmp = NULL;
	content = NULL;
	if (g_data.here_doc == NULL)
		return (NULL);
	tmp = g_data.here_doc;
	if (tmp != NULL)
	{
		g_data.here_doc = tmp->next;
		content = ft_strdup(tmp->content);
		free(tmp->content);
		free(tmp);
		tmp = NULL;
	}
	else
		g_data.here_doc = NULL;
	return (content);
}

int execute_here_doc(char *str)
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

char *get_string(int fd)
{
	int ret;
	char *buffer;
	char tmp[2];

	buffer = NULL;
	while (1)
	{
		ret = read(fd, tmp, 1);
		tmp[ret] = '\0';
		if (ret <= 0)
			break;
		if (buffer == NULL)
		{
			buffer = ft_strdup(tmp);
		}
		else
		{
			buffer = ft_strjoin_custom(buffer, tmp);
		}
		if (ret <= 0)
			break;
	}
	return (buffer);
}

void here_doc_child(int fd, char *delimiter)
{
	char *input;

		while(1)
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

char *get_content(char *delimiter)
{
	int pid;
	int status;
	int pipefd[2];
	char *rtn;

	
	pipe(pipefd);
	pid = fork ();
	if (pid == 0)
	{
		signal(SIGINT, signal_here_document);
		close(pipefd[0]);
		here_doc_child(pipefd[1], delimiter);
	}
	signal(SIGINT, SIG_IGN);
	//signal(SIGQUIT, SIG_IGN);
	waitpid(pid, &status, 0);
	close(pipefd[1]);
	rtn = get_string(pipefd[0]);
	close(pipefd[0]);
	signal(SIGINT, new_prompt);
	return (rtn);
}

void handle_here_doc(t_command **all_commands)
{
	t_command	*actual;
	int i;

	i = 0;
	if (all_commands == NULL || all_commands[0] == NULL)
		return ;
	while (all_commands[i] != NULL)
	{
		actual = all_commands[i];
		if (actual->input != NULL && actual->input->type == DLESS)
		{
			actual->input->content =  get_content(actual->input->file_name);
		}
		i++;
	}
}