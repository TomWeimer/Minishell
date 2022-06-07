/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:16:00 by tweimer           #+#    #+#             */
/*   Updated: 2021/10/24 15:27:00 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static unsigned int	ft_len(unsigned int len, unsigned int size)
{
	while ((size / 10) > 0)
	{
		len++;
		size /= 10;
	}
	return (len);
}

static void	ft_array(unsigned int len, long int number, char *str, int n)
{	
	while (len--)
	{
		str[len] = number % 10 + '0';
		number = number / 10;
	}
	if (n < 0)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	long int		number;
	unsigned int	len;
	unsigned int	size;
	char			*str;

	len = 1;
	number = (long int)n;
	if (n < 0)
		number = number * -1;
	size = number;
	len = ft_len(len, size);
	if (n < 0)
		len++;
	str = malloc (len * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	ft_array(len, number, str, n);
	return (str);
}
