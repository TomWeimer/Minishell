/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:48:51 by tweimer           #+#    #+#             */
/*   Updated: 2022/05/27 13:48:52 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"

int	is_ifs(char c)
{
	char	*ifs;
	int		i;

	ifs = malloc(sizeof(char) * 4);
	ifs[0] = ' ';
	ifs[1] = '\n';
	ifs[2] = '\t';
	ifs[3] = '\0';
	i = 0;
	while (ifs[i])
	{
		if (c == ifs[i])
		{
			free(ifs);
			return (1);
		}
		i++;
	}
	free(ifs);
	return (0);
}

int	is_operator(char *line, int i)
{
	if (line[i] == '|' && line[i + 1] == '|')
		return (OR_IF);
	else if (line[i] == '|' && line[i + 1] != '|')
		return (PIPE);
	else if (line[i] == '&' && line[i + 1] == '&')
		return (AND_IF);
	return (NONE);
}

int	is_redirection(char *line, int i)
{
	if (line[i] == '>' && line[i + 1] == '>')
		return (DGREAT);
	else if (line[i] == '>' && line[i + 1] != '|')
		return (MORE);
	else if (line[i] == '<' && line[i + 1] == '<')
		return (DLESS);
	else if (line[i] == '<' && line[i + 1] != '<')
		return (LESS);
	return (NONE);
}

int	is_special(char *line, int i)
{
	int	type;

	type = is_operator(line, i);
	if (type != NONE)
		return (type);
	type = is_redirection(line, i);
	return (type);
}
