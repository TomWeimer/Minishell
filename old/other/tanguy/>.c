/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   >.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:46:59 by tchappui          #+#    #+#             */
/*   Updated: 2022/03/23 17:40:32 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishel.h"

//fonction qui recupere la sortie 

// O_RDONLY lecture
// O_WRONLY ecriture
// O_RDWR 	lecture + ecriture
// O_CREAT  si le fichier existe pas, le cree
// O_TRUNC 	si le fichier existe ecrie depuis le premier octet
// O_APPEND si le fichier existe ecrie depuis le dernier octet
// O_CLOEXEC a voir surement a utilise

//fonction qui suprime et ecrite la sortie dans un fichier 
int	ft_test(char  *sortie, char *file)
{
	int	fd;
											//pour donner les droits
	fd = open(file, O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR);	//file = le fichier ou doit etre rediriger la sortie, marche que avec le prmeier fichier pointé
	if (fd == -1)
	{
		ft_printf("error");			//gestion d'erreur a revoir
		return (1);
	}
	ft_putstr_fd("la sortie", fd);
}
