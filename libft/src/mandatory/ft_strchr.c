/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:51:07 by tweimer           #+#    #+#             */
/*   Updated: 2021/10/24 13:44:14 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*string;
	char	b;

	b = (char)c;
	string = (char *)s;
	while (*string != '\0')
	{
		if (b == *string)
			return (string);
		string++;
	}
	if (b == '\0')
		return (string);
	return (NULL);
}
