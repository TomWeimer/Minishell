#include "minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s;
	unsigned char	*d;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	s = (unsigned char *)s1;
	d = (unsigned char *)s2;
	while (*s || *d)
	{
		if (*s != *d)
			return (*s - *d);
		s++;
		d++;
	}
	if (*s != *d)
		return (*s - *d);
	return (0);
}

char	*ft_strjoin_custom(char *s1, char *s2)
{
	char	*rtn;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = ft_strlen (s1) + ft_strlen (s2);
	rtn = malloc (sizeof(char) * (size + 1));
	while (s1[i] != '\0')
	{
		rtn[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		rtn[i + j] = s2[j];
		j++;
	}
	rtn[i + j] = '\0';
	free(s1);
	s1 = NULL;
	return (rtn);
}
