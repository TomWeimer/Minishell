#include "minishell.h"

void	ft_exit(t_command *cmd)
{
	(void)cmd;
	kill(0, SIGTERM);
}
