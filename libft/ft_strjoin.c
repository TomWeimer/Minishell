/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:45:10 by tweimer           #+#    #+#             */
/*   Updated: 2021/10/21 17:52:22 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	size;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!s2)
		return (NULL);
	size = ft_strlen (s1) + ft_strlen (s2) + 1;
	ptr = malloc ((size * sizeof(char)));
	if (ptr == NULL)
		return (NULL);
	while (*s1)
	{
		ptr[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		ptr[i] = *s2++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
