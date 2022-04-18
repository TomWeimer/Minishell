#ifndef COMMAND_H
# define COMMAND_H

# define	NO 0
# define	YES 1
# define	MATCH 0
# define	ALLOWED	0
# define	NOT_FOUND	-1
# define	FIRST_PARAM	1
# define	DENIED	1
# define	DIRECTORY	1
# define	FAILED		0
# define	SUCCESS		1
# define	OPTION_ECHO		"-n"
# define	MSG_NOT_FOUND	"cd: no such file or directory: "
# define	MSG_DENIED		"cd: permission denied: "
# define	NEWLINE			"\n"
#include <stdio.h>
#include <unistd.h>
typedef struct s_redirection
{
	int	 					fd;
	int  					type;
	char 					*file_name;
	struct s_redirection	*next;
}t_redirection;

typedef struct s_command
{
	char				*cmd;
	char				**args;
	int					status;
	t_redirection		*input;
	t_redirection		*output;
	struct s_command	*next;
}t_command;
#endif