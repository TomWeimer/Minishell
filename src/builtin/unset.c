/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:47:49 by tweimer           #+#    #+#             */
/*   Updated: 2022/06/06 13:17:33 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment/env.h"
#include "execution/execution.h"
#include <stdlib.h>

void	ft_envfree(t_list *env, char *args)
{
	t_list	*lastenv;
	int		i;

	i = 0;
	lastenv = env;
	args = ft_strcat(args, "=");
	i = 0;
	while (env != NULL)
	{
		if (ft_strdcmp(args, env->content, '=') == 0)
		{
			lastenv->next = env->next;
			free(env->content);
			free(env);
			env = NULL;
			return ;
		}
		if (i == 1)
			lastenv = lastenv->next;
		i = 1;
		env = env->next;
	}
}

int	check_arg_unset(char *args)
{
	int	i;

	i = 0;
	if (ft_isalpha(args[i++]) == NO)
		return (NO);
	while (args[i])
	{
		if (ft_isalnum(args[i]) == NO)
			return (NO);
		i++;
	}
	return (YES);
}

void	ft_unset(t_env *env, char **args)
{
	int	i;

	i = 1;
	while (args[i] != NULL)
	{
		if (check_arg_unset(args[i]) == NO)
		{
			write_error(args[i], "unset: ", UNSET_ERROR);
			g_data.exit_status = 1;
		}
		else
		{
			ft_envfree(env->list, args[i]);
			ft_envfree(env->temp, args[i]);
			g_data.exit_status = 0;
		}
		i++;
	}
}
