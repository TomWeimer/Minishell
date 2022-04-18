/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:06:26 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/25 18:08:30 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	message_error(char *str)
{
	write(2, str, ft_strlen(str));
}

t_input	*init_info(char **input)
{
	t_input	*info;

	info = malloc(sizeof(sizeof(t_input)));
	if (info == NULL)
	{
		message_error(MALLOC);
		exit(EXIT_FAILURE);
	}
	info->nb = get_pipe_nb(input);
	info->pid = get_pid(info->nb);
	info->status = get_status(info->nb);
	info->parent_status = 0;
	return (info);
}

void	init_terminal(char **input)
{
	t_input		*info;
	t_signal	sa;

	new_signal(&sa, &signal_handler);
	info = init_info(input);
	cmd_process(input, info);
	sigaction(SIGINT, &sa, NULL);
}

void	ft_terminal(void)
{
	char		*line;
	t_signal	sa;

	new_signal(&sa, &signal_handler);
	sigaction(SIGINT, &sa, NULL);
	while (TRUE)
	{
		line = readline("prompt > ");
		parsing_input(line);
	}
}
