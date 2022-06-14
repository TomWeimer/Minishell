/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:19:00 by tchappui          #+#    #+#             */
/*   Updated: 2022/06/13 14:57:42 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment/env.h"
#include "minishell.h"

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

void	printenv(t_list *lst)
{
	while (lst != NULL)
	{
		write(1, lst->content, ft_strlen(lst->content));
		write(1, "\n", 1);
		lst = lst->next;
	}
	g_data.exit_status = 0;
}

void	clean_env(t_list *lst)
{
	t_list	*actual;
	t_list	*to_delete;

	to_delete = NULL;
	actual = lst;
	while (actual != NULL)
	{
		to_delete = actual;
		actual = actual->next;
		free(to_delete);
	}
}
