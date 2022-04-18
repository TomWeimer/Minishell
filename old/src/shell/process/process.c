/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:53:19 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/25 17:54:16 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_child(int **pipeline, int nb, int i, char *cmd)
{
	close_unused_pipes(i, nb, pipeline);
	if (i != 0)
	{
		dup2(pipeline[i - 1][0], STDIN_FILENO);
		close(pipeline[i - 1][0]);
	}
	if (i != nb)
	{
		dup2(pipeline[i][1], STDOUT_FILENO);
		close(pipeline[i][1]);
	}
	execute(cmd);
}

void	cmd_loop(t_input *info, t_signal *sa, t_signal *sb, char **input)
{
	int			i;
	int			**pipeline;

	i = 0;
	pipeline = get_pipeline(info->nb);
	while (i < info->nb + 1)
	{
		info->pid[i] = fork();
		if (info->pid[i] == 0)
		{
			sigaction(SIGTERM, sa, NULL);
			sigaction(SIGINT, sa, NULL);
			ft_child(pipeline, info->nb, i, input[i]);
			return ;
		}
		sigaction(SIGTERM, sb, NULL);
		sigaction(SIGINT, sb, NULL);
		if (i <= info->nb)
			waitpid(info->pid[i], &info->status[i], 0);
		i++;
	}
	waitpid(-1, &info->parent_status, 0);
	close_all_pipes(info->nb, pipeline);
}

void	cmd_process(char **input, t_input *info)
{
	t_signal	sa;
	t_signal	sb;

	new_signal(&sa, &child_event);
	new_signal(&sb, &parent_event);
	cmd_loop(info, &sa, &sb, input);
}
