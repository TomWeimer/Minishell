/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:47:45 by tweimer           #+#    #+#             */
/*   Updated: 2022/05/27 13:48:39 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_command *cmd)
{
	char	*buffer;

	(void)cmd;
	buffer = getcwd(NULL, 0);
	write(1, buffer, ft_strlen(buffer));
	write(1, "\n", 1);
	free(buffer);
	buffer = NULL;
}
