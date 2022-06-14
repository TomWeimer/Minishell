/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_base_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:12:30 by tchappui          #+#    #+#             */
/*   Updated: 2022/06/14 14:12:20 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment/env.h"
#include "execution/execution.h"
#include "sub_system/terminal.h"

static char	*find_path3(t_list *list)
{
	char	*rtn;
	int		i;

	i = 0;
	rtn = NULL;
	while (list != NULL)
	{
		if (ft_strncmp(list->content, "PATH=", 5) == 0)
		{
			i = 1;
			break ;
		}
		list = list->next;
	}
	if (i == 1)
		rtn = ft_substr(list->content, 5, ft_strlen(list->content) - 5);
	return (rtn);
}

static char	**find_path2(t_list *list)
{
	char	*arg;
	char	**path;
	int		i;

	path = NULL;
	arg = find_path3(list);
	if (arg == NULL)
		return (path);
	path = ft_split(arg, ':');
	free(arg);
	arg = NULL;
	i = 0;
	while (path[i] != NULL)
	{
		arg = ft_strdup(path[i]);
		free(path[i]);
		path[i] = NULL;
		path[i] = ft_strjoin(arg, "/");
		free(arg);
		arg = NULL;
		i++;
	}
	return (path);
}

// we find the path of the command with the variable $PATH
char	*find_path(t_list *list, char *arg)
{
	char	*cmd;
	char	**path;
	int		i;

	if (access(arg, F_OK) != -1)
	{
		if (ft_strncmp(arg, "./", 2) == 0
			|| ft_strncmp(arg, "/", 1) == 0)
			return (arg);
		return (NULL);
	}
	i = -1;
	path = find_path2(list);
	if (path != NULL)
	{
		while (path[++i] != 0)
		{
			cmd = ft_strjoin(path[i], arg);
			if (access(cmd, F_OK) == -1)
				free(cmd);
			else
				return (cmd);
		}
	}
	return (NULL);
}
