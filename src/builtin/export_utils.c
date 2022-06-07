/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:21:22 by tchappui          #+#    #+#             */
/*   Updated: 2022/06/06 12:21:29 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment/env.h"
#include "execution/execution.h"

void	addexport_equal(t_list *list, char *str)
{
	t_list	*newlist;

	newlist = list;
	while (list != NULL)
	{
		if (ft_strdcmp(list->content, str, '=') == 0)
		{
			free (list->content);
			list->content = NULL;
			list->content = ft_strdup(str);
			return ;
		}
		list = list->next;
	}
	ft_lstadd_back(&newlist, ft_lstnew(str));
}

void	add_export(char *args, t_list *list, t_list *temp)
{
	int	i;

	while (temp != NULL)
	{
		if (ft_strdcmp(args, temp->content, '=') == 0)
		{
			ft_lstadd_back(&list, ft_lstnew(temp->content));
			return ;
		}
		temp = temp->next;
	}
	i = 0;
	while (args[i] != '=')
		i++;
	args[i] = 0;
	ft_lstadd_back(&list, ft_lstnew(args));
}

void	addexport(char *args, t_env *env)
{
	t_list	*newenv;

	newenv = env->list;
	ft_strcat(args, "=");
	while (newenv != NULL)
	{
		if (ft_strdcmp(args, newenv->content, '=') == 0)
			return ;
		newenv = newenv->next;
	}
	add_export(args, env->list, env->temp);
}
