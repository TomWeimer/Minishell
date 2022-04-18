/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:16:06 by tweimer           #+#    #+#             */
/*   Updated: 2021/10/21 13:55:40 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr;
	char	*s;
	char	*d;

	d = dst;
	s = (char *)src;
	ptr = dst;
	if (!s && !d)
		return (NULL);
	while (n-- > 0)
		*ptr++ = *s++;
	return (d);
}
