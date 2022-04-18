/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:07:36 by tweimer           #+#    #+#             */
/*   Updated: 2021/10/24 12:25:51 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_gets_start(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	ft_gets_end(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		size;

	if (!s1)
		return (NULL);
	if (ft_gets_start(s1, set) >= ft_gets_end(s1, set))
		return (ft_strdup(""));
	size = (ft_gets_end(s1, set) - ft_gets_start(s1, set));
	str = malloc (size * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1 + ft_gets_start(s1, set), size + 1);
	return (str);
}
