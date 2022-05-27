/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:38:14 by tchappui          #+#    #+#             */
/*   Updated: 2022/04/22 14:25:57 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strdcmp(char *s1, char *s2, char d)
{
	int	i;
	int	j;
	i = 0;
	j = 0;
	while (s1[i] != d && s1[i] != '\0')
		i++;
	while (s2[j] != d && s2[j] != '\0')
		j++;
	if (i < j)
		i = j;
	j = 0;
	while (j < i)
	{
		if (s1[j] != s2[j])
			return (1);
		j++;
	}
	return (0);
}
