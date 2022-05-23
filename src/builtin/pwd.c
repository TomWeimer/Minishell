#include "minishell.h"

void	ft_pwd(t_command *cmd)
{
	char	*buffer;
	
	(void)cmd;
	buffer = getcwd(NULL, 0);
	write(1, buffer, ft_strlen(buffer));
	write(1, "\n",1);
	free(buffer);
	buffer = NULL;
}
