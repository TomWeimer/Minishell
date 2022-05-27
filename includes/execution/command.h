#ifndef COMMAND_H
# define COMMAND_H

# define	NO 				0
# define	YES 			1
# define	MATCH			0
# define	ALLOWED			0
# define	NOT_FOUND		-1
# define	FIRST_PARAM		1
# define	DENIED			1
# define	DIRECTORY		1
# define	FAILED			0
# define	SUCCESS			1
# define	OPTION_ECHO		"-n"
// structures:
typedef struct s_redirection
{
	int						fd;
	int						type;
	char					*content;
	char					*file_name;
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

void 		print_to_outfiles(char *str, t_command *cmd);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strjoin_custom(char *s1, char *s2);
#endif