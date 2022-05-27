/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:14:37 by tweimer           #+#    #+#             */
/*   Updated: 2022/05/22 17:55:01 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	if ((start + len) > ft_strlen(s))
		ptr = malloc(ft_strlen(s) + 1 * sizeof(char));
	else
		ptr = malloc (len * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s[start] && i < len && start < ft_strlen(s))
	{
		ptr[i] = s[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
