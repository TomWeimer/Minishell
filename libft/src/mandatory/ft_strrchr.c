/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:12:14 by tweimer           #+#    #+#             */
/*   Updated: 2021/10/24 13:45:29 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*output;
	int		found;
	char	b;

	b = (char)c;
	found = 0;
	i = 0;
	while (s[i])
	{
		if (b == *s)
		{
			found = 1;
			output = (char *)s;
		}
		s++;
	}
	if (b == '\0')
		output = (char *)s;
	else if (!found)
		output = NULL;
	return (output);
}
