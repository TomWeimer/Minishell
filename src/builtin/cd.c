#include "minishell.h"

void	ft_cd(t_command *cmd)
{
	int	user_access;

	if (cmd->args[DIRECTORY] != NULL)
	{
		user_access = access(cmd->args[DIRECTORY], F_OK | X_OK);
		if (user_access == DENIED)
			write_error(cmd->args[DIRECTORY], "cd :");
		else
			chdir(cmd->args[DIRECTORY]);
	}
	else
		write_error(NULL, "cd :");
}
