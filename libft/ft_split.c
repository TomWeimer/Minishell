/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:51:22 by tweimer           #+#    #+#             */
/*   Updated: 2021/10/24 15:25:14 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

static int	ft_gets_count_words(char const *s, char c)
{
	unsigned int		count;
	unsigned int		i;

	if (!s[0])
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	ft_write_split(char **dest, char *str, char c, int word_number)
{
	size_t	i;
	size_t	j;
	int		a;

	a = 0;
	i = 0;
	j = 0;
	while (i < ft_strlen(str))
	{	
		j = 0;
		if (str[i] == c)
			i++;
		else
		{	
			while (str[i + j] != c && str[i + j] != '\0')
				j++;
			dest[a] = ft_substr(str, i, j);
			i += j;
			a++;
		}
	}
	dest[word_number] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		words_count;

	if (!s)
		return (0);
	words_count = ft_gets_count_words(s, c);
	dest = (char **)malloc ((words_count + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	dest[words_count] = NULL;
	ft_write_split(dest, (char *)s, c, words_count);
	return (dest);
}
