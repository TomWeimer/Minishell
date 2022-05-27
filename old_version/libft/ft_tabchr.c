/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:26:39 by tchappui          #+#    #+#             */
/*   Updated: 2022/04/11 14:27:09 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tabchr(char **str, char c)
{
	int	i;
	int	j;

	i = 0;
	while (str[++i] != NULL)
	{
		j = 0;
		while(str[i][j])
		{
			if (str[i][j] == c)
				return (1);
			j++;
		}
	}
	return (0);
}
