/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:47:30 by tweimer           #+#    #+#             */
/*   Updated: 2022/06/05 17:03:04 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	ft_option(char *str)
{
	int	i;

	i = 1;
	if (str[0] == '-' && str[1] == 'n')
	{
		while (str[i] == 'n')
		{
			i++;
			if (str[i] == 0)
				return (MATCH);
		}
	}
	return (1);
}

char	*new_buffer(t_command *cmd, int i, char *buffer, int option)
{
	if (buffer == NULL)
		buffer = ft_strdup(cmd->args[i]);
	else
		buffer = ft_strjoin_custom(buffer, cmd->args[i]);
	if (cmd->args[i + 1] != NULL && cmd->args[i + 1][0] != 0)
		buffer = ft_strjoin_custom(buffer, " ");
	else if (option == NO && cmd->args[i + 1] == 0)
		buffer = ft_strjoin_custom(buffer, "\n");
	return (buffer);
}

void	ft_echo(t_command *cmd)
{
	int		i;
	int		option;
	char	*buffer;

	i = FIRST_PARAM;
	option = NO;
	buffer = NULL;
	while (cmd->args[i] != NULL)
	{
		if (ft_option(cmd->args[i]) == MATCH && buffer == NULL)
			option = YES;
		else
			buffer = new_buffer(cmd, i, buffer, option);
		i++;
	}
	if (buffer == NULL && option == NO)
		buffer = ft_strdup("\n");
	if (buffer != NULL)
	{
		write(1, buffer, ft_strlen(buffer));
		free(buffer);
		buffer = NULL;
	}
	g_data.exit_status = 0;
}
