/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:55:18 by tchappui          #+#    #+#             */
/*   Updated: 2022/04/15 17:11:43 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_addenv(t_env *env, t_list *list, char *str)
{
	t_list	*newtemp;

printf("tomi");
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
