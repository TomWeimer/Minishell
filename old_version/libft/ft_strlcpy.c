/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:38:35 by tweimer           #+#    #+#             */
/*   Updated: 2022/05/22 17:55:01 by tweimer          ###   ########.fr       */
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
