/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:54:19 by tchappui          #+#    #+#             */
/*   Updated: 2022/05/23 11:42:46 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment/env.h"
#include "execution/execution.h"
#include <string.h>

void no_prompt(int sig);
void new_prompt(int sig);
static char	*find_path3(t_list *list)
{
	char	*rtn;
	int		i; 

	i = 0;
	while (list != NULL)
	{
		if (ft_strncmp(list->content, "PATH=", 5) == 0)
			break ;
		list = list->next;
		i++;
	}
	rtn = ft_substr(list->content, 5, ft_strlen(list->content) - 5);
	return (rtn);
}

static char	**find_path2(t_list *list)
{
	char	*arg;
	char	**path;
	int		i;

	arg = NULL;
	arg = find_path3(list);
	path = ft_split(arg, ':');
	free(arg);
	i = 0;
	while (path[i] != NULL)
	{
		arg = ft_strdup(path[i]);
		free(path[i]);
		path[i] = NULL;
		path[i] = ft_strjoin(arg, "/");
		free(arg);
		i++;
	}
	return (path);
}

static char	*find_path(t_list *list, char *arg)
{
	char	*cmd;
	char	**path;
	int		i;

	if (access(arg, F_OK) != -1)
	{
		if (ft_strncmp(arg, "./", 2) == 0)
			return (arg);
		return (NULL);
	}
	i = 0;
	path = find_path2(list);
	while (path[i] != 0)
	{
		cmd = ft_strjoin(path[i], arg);
		if (access(cmd, F_OK) == -1)
		{
			free(cmd);
			cmd = NULL;
			i++;
		}
		else
			return (cmd);
	}
	return (NULL);
}

char **env_tab(t_env *env)
{
	t_list *actual;
	char **envp;
	int i;

	i = 0;
	envp = malloc(sizeof(char *) * (env->envsize + 1));
	actual = env->list;
	while (actual->next != NULL)
	{
		envp[i] = ft_strdup(actual->content);
		actual = actual->next;
		i++;
	}
	return (envp);
}

int pipe_base_builtin(t_tree *node, t_env *env)
{
	char	*cmd;
	pid_t	out;
	int		status;

	cmd = NULL;
	cmd = find_path(env->list, node->cmd->args[0]);
	if (cmd != NULL) // && n'est pas un pipe
	{
		out = fork();
	 // creer un nouveau process
		if (out == 0)
		{
			signal(SIGINT, handler_child);
			if (execve(cmd, node->cmd->args, g_envp) == -1) // si reussi quitte le process
			{
				if (cmd != NULL)
					free (cmd);
				cmd = NULL;
				exit(1);
			}
			exit(0);
		}
		else
		{
			signal(SIGINT, no_prompt);
			waitpid(out, &status, 0);
			signal(SIGINT, new_prompt);
			free (cmd);
			cmd = NULL;
			return (0);
		}
	}
	else
	{
		printf("Minishell: %s: command not found\n", node->cmd->args[0]);
		return (0);
	}
	return (0);
}

int	base_builtin(char **str, t_env *env) //execute les commande de base
{
	char	*cmd;
	pid_t	out;
	int		status;

	cmd = NULL;
	cmd = find_path(env->list, str[0]);
	if (cmd != NULL) // && n'est pas un pipe
	{
		out = fork();
	 // creer un nouveau process
		if (out == 0)
		{
			signal(SIGINT, handler_child);
			if (execve(cmd, str, NULL) == -1) // si reussi quitte le process
			{
				if (cmd != NULL)
					free (cmd);
				cmd = NULL;
				exit(1);
			}
			exit(0);
		}
		else
		{
			signal(SIGINT, no_prompt);
			waitpid(out, &status, 0);
			
			signal(SIGINT, new_prompt);
			free (cmd);
			cmd = NULL;
			return (0);
		}
	}
	else
	{
		printf("Minishell: %s: command not found\n", str[0]);
		return (0);
	}
	return (0);
}