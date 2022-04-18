/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:07:21 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/25 18:07:47 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
	DELIMITER:

	step1:	check les delimiters |
			0 pipe == 	1 commande;
			1 pipe == 	2 commande;
			n pipe ==	n + 1;
	step2: 	creer n nombre de child

	step2: split la ligne de code en differentes commandes
			delimiter == space ' '
			cmd + args = char **cmd;
	step3: VAR ENV
			remplacer la valeur des variables qui comprennent
			un $ si une variable n'existe pas remplacer par rien
			si c'est une fonction stocker l'output dans ces variables

	step4:	Aller chercher a l'aide de la variable PATH
			Si les commandes existent

	step5:	Executer les commandes, si elles ne s'executent pas
			envoie simplement un message d'erreur
	step6:	free 
*/
void	parsing_input(char *line)
{
	char	**input;

	input = ft_split(line, '|');
	init_terminal(input);
	return ;
}
