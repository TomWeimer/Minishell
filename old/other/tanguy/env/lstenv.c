/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:49:33 by tchappui          #+#    #+#             */
/*   Updated: 2022/04/15 14:50:17 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->next = 0;
	new->content = ft_strdup(content);
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst->next != NULL)
		{
			lst = lst->next;
			i++;
		}
	return (i);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end_lst;

	if (new)
	{
		if(!*lst)
		{
			*lst = new;
			return;	
		}
		end_lst = ft_lstlast(*lst);
		end_lst->next = new;
	}
}

t_list	*ft_lstreplace(t_list *lst, char *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->next = lst->next;
	new->content = ft_strdup(content);
	free(lst);
	return (new);
}

void	printlst(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
}
