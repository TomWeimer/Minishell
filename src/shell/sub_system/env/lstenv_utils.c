/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstenv_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:38:54 by tchappui          #+#    #+#             */
/*   Updated: 2022/06/05 21:40:10 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment/env.h"
#include <stdlib.h>

void	printlst(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
}

int	ft_lstlen(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
