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
/*
int get_nb_pipe(char *str)
{
	int nb;

	nb = 0;
	while (str[i])
	{
		if (str[i] == '|')
			nb++;
		i++;
	}
	return (nb);
}
 
int get_input(char **input, char *line)
{
	input = ft_split(line);
	return(get_nb_pipe(line));
} */

void parsing(int *exit, char *line)
{
	(void) exit;
	(void) line;
	return;
	/* char **input;
	int ret;
	int nb_pipe;

	input = NULL;
	nb_pipe = get_input(input, line);
	if (nb_pipe > 0)
	{
		pipe_function();
	}
	else
		ft_function(input[0]);
	return ; */
}