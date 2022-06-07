/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:38:35 by tweimer           #+#    #+#             */
/*   Updated: 2021/10/21 15:36:38 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	char	*d;
	char	*s;
	size_t	len;

	s = (char *)src;
	d = dest;
	len = ft_strlen(src);
	if (dstsize > 0)
	{
		while (--dstsize && *s)
		{
			*d++ = *s++;
		}
		*d = '\0';
	}
	return (len);
}
