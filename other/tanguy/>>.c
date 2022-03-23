/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   >>.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:17:47 by tchappui          #+#    #+#             */
/*   Updated: 2022/03/23 17:34:47 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishel.h"

//fonction qui recupere la sortie 

//fonction qui va ecrire la sortie a partir de la fin, avec O_APPEND
int	ft_test(char  *sortie, char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IWUSR | S_IRUSR);	//file = le fichier ou doit etre rediriger la sortie
	if (fd == -1)
	{
		ft_printf("error");			//gestion d'erreur a revoir
		return (1);
	}
	ft_putstr_fd("la sortie", fd);
}

// surment d'autre chose a gere