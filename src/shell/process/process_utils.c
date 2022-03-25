/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:59:23 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/25 18:02:50 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_all_pipes(int nb, int **pipeline)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		close(pipeline[i][0]);
		close(pipeline[i][1]);
		i++;
	}
}

void	free_all_pipes(int nb, int **pipeline)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		free(pipeline[i]);
		pipeline[i] = NULL;
		i++;
	}
}

void	close_unused_pipes(int process_num, int nb, int **pipeline)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (i == 0)
			close(pipeline[0][0]);
		else if (i != 0 && i == process_num - 1)
			close(pipeline[i][1]);
		else if (i != 0 && i == process_num)
		{
			close(pipeline[i][0]);
			if (i == nb)
				close(pipeline[i][1]);
		}
		else if (i != 0)
		{
			close(pipeline[i][0]);
			close(pipeline[i][1]);
		}
		i++;
	}
}

int	get_pipe_nb(char **input)
{
	int	i;

	i = 0;
	while (input[i] != NULL)
		i++;
	return (i - 1);
}

int	**get_pipeline(int nb)
{
	int	i;
	int	**rtn;

	i = 0;
	rtn = malloc(sizeof(int *) * (nb + 1));
	while (i < nb)
	{
		rtn[i] = malloc(sizeof(int) * 2);
		pipe(rtn[i]);
		i++;
	}
	return (rtn);
}
