#include "minishell.h"

char	*new_buffer(t_command *cmd, int i, char *buffer, int option)
{
	if (buffer == NULL)
		buffer = ft_strdup(cmd->args[i]);
	else
		buffer = ft_strjoin_custom(buffer, cmd->args[i]);
	if (cmd->args[i + 1] != NULL)
		buffer = ft_strjoin_custom(buffer, " ");
	else if (option == NO)
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
		if (ft_strcmp(cmd->args[i], OPTION_ECHO) == MATCH)
			option = YES;
		else
		{
			buffer = new_buffer(cmd, i, buffer, option);
		}
		i++;
	}
	print_to_outfiles(buffer, cmd);
	free(buffer);
	buffer = NULL;
}
