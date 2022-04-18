/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:37:39 by tweimer           #+#    #+#             */
/*   Updated: 2021/10/21 14:22:53 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ptr;
	const char	*s;
	char		*lasts;
	char		*lastd;

	ptr = dst;
	s = src;
	if (!s && !ptr)
		return (NULL);
	if (ptr < s)
		while (len--)
			*ptr++ = *s++;
	else
	{
		lasts = (char *)(s + (len - 1));
		lastd = (char *)(ptr + (len - 1));
		while (len--)
			*lastd-- = *lasts--;
	}	
	return (dst);
}
