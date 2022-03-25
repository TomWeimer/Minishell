/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:15:57 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/25 18:17:25 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(char *cmd)
{
	char	**args;
	char	*cmd_path;
	int		i;
	char	*path;

	path = "./bin/";
	i = 0;
	args = ft_split(cmd, ' ');
	cmd_path = ft_strjoin(path, args[0]);
	execve(cmd_path, args, NULL);
}
