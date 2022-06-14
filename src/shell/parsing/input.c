/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:49:34 by tweimer           #+#    #+#             */
/*   Updated: 2022/06/14 13:23:11 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"
#include "sub_system/terminal.h"

char	*delete_border_ifs(char *tmp)
{
	int		i;
	int		j;
	int		size;
	char	*input;

	input = NULL;
	i = 0;
	size = ft_strlen(tmp) - 1;
	j = size;
	while (tmp[i] != '\0' && is_ifs(tmp[i]) == YES)
		i++;
	if (i == j + 1)
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	while (j > 0 && is_ifs(tmp[j]) == YES)
		j--;
	input = ft_substr(tmp, i, (j - i) + 1);
	free(tmp);
	tmp = NULL;
	return (input);
}

char	*get_user_input(void)
{
	char	*input;
	char	*tmp;

	tmp = NULL;
	input = NULL;
	block_signals_from_keyboard();
	tmp = readline("prompt $$ ");
	if (tmp == NULL)
	{
		printf("exit\n");
		exit(EXIT_SUCCESS);
	}
	add_history(tmp);
	input = delete_border_ifs(tmp);
	g_data.input = input;
	return (input);
}
