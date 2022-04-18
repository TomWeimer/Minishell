
#include "../../includes/command.h"
#include "../../includes/minishell.h"

void	ft_pwd(t_command *cmd)
{
	char *buffer;
	(void)cmd;
	buffer = getcwd(NULL, 0);
	printf("%s\n", buffer);
	//print_cmd(buffer, cmd);
	free(buffer);
	buffer = NULL;
}
