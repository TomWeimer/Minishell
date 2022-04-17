/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:40:06 by tchappui          #+#    #+#             */
/*   Updated: 2022/04/15 17:17:17 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_envfree(t_list *env, char *args)
{
	t_list	*lastenv;
	int		i;

	i = 0;
	lastenv = env;
	while (args[i] != 0)
		i++;
	args = ft_strcat(args, "=");
	i = 0;
	while (env != NULL)
	{
		if (ft_strdcmp(args, env->content, '=') == 0)
		{
			lastenv->next = env->next;
			free(env->content);
			free(env);
			return ;
		}
		if (i == 1)
			lastenv = lastenv->next;
		i = 1;
		env = env->next;
	}
}

void	ft_unset(t_env *env, char **args)
{
	int	i;

	i = 1;
	while (args[i] != NULL)
	{
		ft_envfree(env->list, args[i]);
		ft_envfree(env->temp, args[i]);
		i++;
	}
}
