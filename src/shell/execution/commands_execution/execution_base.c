/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:54:19 by tchappui          #+#    #+#             */
/*   Updated: 2022/06/09 15:02:38 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment/env.h"
#include "execution/execution.h"
#include "sub_system/terminal.h"
#include <string.h>

char	**env_tab(t_env *env)
{
	t_list	*actual;
	char	**envp;
	int		i;

	i = 0;
	envp = malloc(sizeof(char *) * (ft_lstlen(env->list)));
	actual = env->list;
	while (actual != NULL)
	{
		envp[i] = ft_strdup(actual->content);
		actual = actual->next;
		i++;
	}
	return (envp);
}

int	pipe_base_builtin(t_tree *node)
{
	char	*cmd;
	pid_t	out;
	int		status;
	char	**envp;

	cmd = find_path(g_data.env->list, node->cmd->args[0]);
	if (cmd != NULL)
	{
		out = fork();
		exec_signals();
		envp = env_tab(g_data.env);
		if (out == 0)
			execve(cmd, node->cmd->args, envp);
		waitpid(out, &status, 0);
		if (WIFEXITED(status))
			g_data.exit_status = WEXITSTATUS(status);
	}
	else
	{
		write_error(node->cmd->args[0], "Minishel: ", CMD_NOT_FOUND);
		return (1);
	}
	free(cmd);
	block_signals_from_keyboard();
	return (0);
}

//	We create a new process, and execute the commands with
//	execve
int	base_builtin(char **str)
{
	char	*cmd;
	pid_t	out;
	int		status;
	char	**env;

	cmd = find_path(g_data.env->list, str[0]);
	if (cmd != NULL && str[0][0] != '\0')
	{
		out = fork();
		exec_signals();
		env = env_tab(g_data.env);
		if (out == 0)
			execve(cmd, str, env);
		waitpid(out, &status, 0);
		if (WIFEXITED(status))
			g_data.exit_status = WEXITSTATUS(status);
	}
	else
	{
		write_error(str[0], "Minishel: ", CMD_NOT_FOUND);
		return (1);
	}
	block_signals_from_keyboard();
	return (0);
}
