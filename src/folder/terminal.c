/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:06:26 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/21 12:24:07 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_strlen(char *str)
{
	int i = 0;
	if (str == NULL)
		return (1);
	while (str[i])
		i++;
	return (i);
}

void ft_terminal(void)
{
	char *line;
	int exit;

	exit = 1;
	while (exit)
	{
		line = readline("prompt >  ");
		//NE MARCHE PAS ENCORE
		//parsing(&exit, line);
		write(1, "\n", 1);
	}
	free (line);
	return ;
}