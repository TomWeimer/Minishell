/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:03:53 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/25 18:04:53 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		rl_on_new_line();
		write(2, "\n", 1);
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	child_event(int sig)
{
	if (sig == SIGTERM)
	{
		exit(1);
	}
	if (sig == SIGINT)
	{
		exit(1);
	}
}

void	parent_event(int sig)
{
	if (sig == SIGTERM)
	{
		exit(1);
	}
	if (sig == SIGINT)
	{
		return ;
	}
}
