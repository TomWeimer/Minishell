/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:48:56 by tweimer           #+#    #+#             */
/*   Updated: 2022/05/27 13:54:02 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_checkequal(char **args, t_env *env)
{
	int	i;

	i = -1;
	while (args[++i] != NULL)
	{
		if (ft_strchr(args[i], '=') != NULL)
			ft_addenv(env, env->list, args[i]);
		else
			return (0);
	}
	return (9);
}

int	is_builtin(char *str)
{
	char	**builtin;
	int		i;

	i = -1;
	builtin = malloc ((7 + 1) * sizeof(char *));
	builtin[0] = "echo";
	builtin[1] = "cd";
	builtin[2] = "pwd";
	builtin[3] = "exit";
	builtin[4] = "export";
	builtin[5] = "unset";
	builtin[6] = "env";
	builtin[7] = NULL;
	while (builtin[++i])
	{
		if (ft_strcmp(str, builtin[i]) == 0)
		{
			free(builtin);
			builtin = NULL;
			return (i + 1);
		}
	}
	free(builtin);
	builtin = NULL;
	return (0);
}

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
