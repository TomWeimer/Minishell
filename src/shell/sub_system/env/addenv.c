/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:18:46 by tchappui          #+#    #+#             */
/*   Updated: 2022/06/05 21:34:49 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment/env.h"
#include "execution/execution.h"

void	ft_lastcmd(int ok)
{
	if (ok == CMD_ECHO)
		ft_addenv(g_data.env, g_data.env->list, "_=/Users/bin/echo");
	else if (ok == CMD_CD)
		ft_addenv(g_data.env, g_data.env->list, "_=/Users/bin/cd");
	else if (ok == CMD_PWD)
		ft_addenv(g_data.env, g_data.env->list, "_=/Users/bin/pwd");
	else if (ok == CMD_EXIT)
		ft_addenv(g_data.env, g_data.env->list, "_=/Users/bin/exit");
	else if (ok == CMD_EXPORT)
		ft_addenv(g_data.env, g_data.env->list, "_=/Users/bin/export");
	else if (ok == CMD_UNSET)
		ft_addenv(g_data.env, g_data.env->list, "_=/Users/bin/unset");
	else if (ok == CMD_ENV)
		ft_addenv(g_data.env, g_data.env->list, "_=/Users/bin/env");
}

void	ft_addenv(t_env *env, t_list *list, char *str)
{
	t_list	*newtemp;

	while (list != NULL)
	{
		if (ft_strdcmp(list->content, str, '=') == 0)
		{
			free (list->content);
			list->content = ft_strdup(str);
			return ;
		}
		list = list->next;
	}
	newtemp = env->temp;
	while (newtemp != NULL)
	{
		if (ft_strdcmp(newtemp->content, str, '=') == 0)
		{
			free (newtemp->content);
			newtemp->content = ft_strdup(str);
			return ;
		}
		newtemp = newtemp->next;
	}
	ft_lstadd_back(&env->temp, ft_lstnew(str));
}
