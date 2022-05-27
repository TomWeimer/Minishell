#ifndef ERROR_H
# define ERROR_H

// define:
# define	MALLOC_ERROR	"ERROR: failed to allocate memory !\n"
# define	MSG_NOT_FOUND	"cd: no such file or directory: "
# define	MSG_DENIED		"cd: permission denied: "
# define	NEWLINE 		"\n"
# define	CMD_NOT_FOUND	"Error: command not found\n"

// prototypes:
void	write_syntax_token_error(int token_type);
void	write_error(char *message_extra, char *command);
#endif