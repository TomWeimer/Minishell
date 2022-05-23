/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:40:45 by tchappui          #+#    #+#             */
/*   Updated: 2022/05/19 19:01:03 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution/execution.h"

void	free_tab(char **tab) //a mettre dans la libft
{
	int	i;

	i = -1;
	while (tab[++i] != NULL)
		free(tab[i]);
	free(tab);
}

char	*ft_asterix(void)
{
	char			*ret;
	DIR				*dp;
	struct dirent	*dirp;

	dp = opendir(".");
	ret = NULL;
	dirp = readdir(dp);
	while (dirp != NULL)
	{
		if (dirp->d_name[0] != '.')
		{
			if (ret != NULL)
				ret = ft_strjoin_custom(ret, " ");
			if (ret != NULL)
				ret = ft_strjoin_custom(ret, dirp->d_name);
			else
				ret = ft_strdup(dirp->d_name);
		}
		dirp = readdir(dp);
	}
	closedir(dp);
	return (ret);
}

static void	reallocargs(t_command *cmd, int len, char **filenames)
{
	char	**ret;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = -1;
	k = -1;
	ret = malloc((ft_tablen(cmd->args) + ft_tablen(filenames) + 1)
			* sizeof (char *));
	while (cmd->args[++i] != NULL)
	{
		if (i == len)
			while (filenames[++k] != NULL)
				ret[++j] = ft_strdup(filenames[k]);
		else
			ret[++j] = ft_strdup(cmd->args[i]);
	}
	ret[++j] = NULL;
	i = -1;
	cmd->args = malloc((ft_tablen(ret) + 1) * sizeof (char *));
	while (ret[++i] != NULL)
		cmd->args[i] = ft_strdup(ret[i]);
	cmd->args[i] = NULL;
	free_tab(ret);
}

static char	**cmp_start(char *args, char **path)
{
	char	**ret;
	int		i;
	int		j;
	int		len;

	ret = malloc(ft_tablen(path) * sizeof (char *));
	i = -1;
	j = -1;
	while (path[++i] != NULL)
	{
		len = ft_strlen(args);
		if (ft_strncmp(args, path[i], len - 1) == 0)
			ret[++j] = ft_strdup(path[i]);
	}
	ret[++j] = NULL;
	return (ret);
}

static char	**cmp_end(char *args, char **path)
{
	char	**ret;
	int		i;
	int		j;
	int		size_path;
	int		len;

	ret = malloc(ft_tablen(path) * sizeof (char *));
	i = -1;
	j = -1;
	while (path[++i] != NULL)
	{
		len = ft_strlen(args);
		size_path = ft_strlen(path[i]);
		while (len > 0 && path[i][size_path] == args[len])
		{
			len--;
			size_path--;
			if (args[len] == '*')
				ret[++j] = ft_strdup(path[i]);
		}
	}
	if (ret) // probleme
	{
		ret[0] = ft_strdup(args);
		ret[1] = NULL;
		return (ret);
	}
	ret[++j] = NULL;
	return (ret);
}

static char	**chek_asterix(char *args, char **path)
{
	int	size;

	size = ft_strlen(args);
	if (size == 1)
		return (path);
	else if (args[0] == '*')
		return (cmp_end(args, path));
	else if (args[size - 1] == '*')
		return (cmp_start(args, path));
	return (path);
}

void	ft_wildcard(t_command *cmd)
{
	char	**path;
	int		i;
	char	**filenames;

	i = -1;
	path = ft_split(ft_asterix(), ' ');
	while (cmd->args[++i] != NULL)
	{
		if (ft_strchr(cmd->args[i], 42) != NULL)
		{
			filenames = chek_asterix(cmd->args[i], path);
			reallocargs(cmd, i, filenames);
			free_tab(filenames);
		}
	}
}
