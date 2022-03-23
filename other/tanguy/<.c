/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   <.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:56:58 by tchappui          #+#    #+#             */
/*   Updated: 2022/03/23 17:38:58 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishel.h"

//fonction qui lit le fichier et quit return son contenu
char	*test(char *file)
{
	int		fd;
	char	*ret;

	fd = open(file, O_RDONLY);   
	if (fd == -1)
	{
		ft_printf("error");
		return (1);
	}
	read(fd, ret, 10000);  // faire une boucle avec un strjoin temps qu'on est pas a la fin
	close(fd);
	return (ret);
}