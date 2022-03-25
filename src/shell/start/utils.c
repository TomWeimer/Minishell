/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:08:40 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/25 18:09:30 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*get_status(int nb)
{
	int	*rtn;
	int	i;

	i = 0;
	rtn = malloc(sizeof(int) * nb);
	if (rtn == NULL)
	{
		message_error(MALLOC);
		exit(EXIT_FAILURE);
	}
	while (i < nb)
	{
		rtn[i] = 0;
		i++;
	}
	return (rtn);
}

pid_t	*get_pid(int nb)
{
	pid_t	*rtn;
	int		i;

	i = 0;
	rtn = malloc(sizeof(pid_t) * nb);
	if (rtn == NULL)
	{
		message_error(MALLOC);
		exit(EXIT_FAILURE);
	}
	while (i < nb)
	{
		rtn[i] = 0;
		i++;
	}
	return (rtn);
}
