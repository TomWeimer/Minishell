/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:19:00 by tchappui          #+#    #+#             */
/*   Updated: 2022/05/19 18:21:09 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment/env.h"
#include <stdlib.h>

void	ft_env(t_list **env, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != 0)
	{
		ft_lstadd_back(env, ft_lstnew(envp[i]));
		i++;
	}
}

char	*ft_compart(char *arg, t_list *env, t_list *temp)
{
	int	i;

	i = ft_strlen(arg);
	while (env != NULL)
	{
		if (ft_strdcmp (env->content, "_=", '=') == 0
			&& ft_strcmp(arg, "_=") == 0)
			return (env->content + 13);
		if (ft_strdcmp(arg, env->content, '=') == 0)
			return (env->content + i + 1);
		env = env->next;
	}
	while (temp != NULL)
	{
		if (ft_strdcmp(arg, temp->content, '=') == 0)
			return (temp->content + i + 1);
		temp = temp->next;
	}
	return (NULL);
}

char	**replaceargs(char **args, int i, int j, t_env *env)
{
	char	*retenv;
	char	*t;

	retenv = ft_compart(args[i] + j + 1, env->list, env->temp);
	j--;
	if (retenv != NULL)
		t = malloc(j + ft_strlen(retenv));
	else
		t = malloc(j + 1);
	j = -1;
	while (args[i][++j] != '$')
		t[j] = args[i][j];
	t[j] = 0;
	if (retenv != NULL)
		args[i] = ft_strjoin(t, retenv);
	else
		args[i] = ft_strdup(t);
	free(t);
	return (args);
}

char	**ft_remplaceargs(char **args, t_env *env)
{
	int		i;
	int		j;
	char	**t;

	i = 0;
	t = NULL;
	while (args[++i] != NULL)
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == '$' && args[i][j + 1] != 0)
			{
				t = replaceargs(args, i, j, env);
				break ;
			}
			j++;
		}
	}
	if (t != NULL)
		return (t);
	return (args);
}
