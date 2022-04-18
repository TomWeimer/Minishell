#ifndef TOKENS_H
# define TOKENS_H


#include <stdlib.h>
# define NONE 0
/*
--------------------------------------------------------------------------------
								Shell Tokenizer
--------------------------------------------------------------------------------
In order to parse the command line, we need to split it into different part.
These parts are called "token", the tokens used in this project are listed below.
example:
	 echo foo > bar.txt  ->	CMD PARAM LESS OUTFILE

-------------------------------------------------------------------------------- 
	OPERATORS:				*/
# define	PIPE		10	// symbol:	'|'
# define	OR_IF		11	// symbol:	'||'
# define	AND_IF		12	// symbol:	'&&'

/*	REDIRECTIONS:			*/
# define	LESS		13	// symbol:	'<'
# define	MORE		14	// symbol:	'>'
# define	DLESS		15	// symbol:	'<<'
# define	DGREAT		16	// symbol:	'>>'

/*	CMD	TOKENS:				*/
# define	WORD		17	//	delimiter WORD delimiter
# define	CMD			18	//	the command
# define	PARAM		19	//	the parameters of the command
# define	SQUOTED		20	//	symbol:	" WORD "
# define	DQUOTED 	21	//	symbol:	' WORD '
# define	INFILE		22	//	Appear after a redirection, is a file_name
# define	OUTFILE		23	//	Appear after a redirection, is a file_name

//tokenizer
# define LAST NULL

/* 									STRUCTURES									*/

typedef struct s_token
{
	int				type;
	char			*word;
	struct s_token	*next;
}t_token;

typedef struct s_group_token
{
	t_token	*first;
}t_group_token;

/* 									PROTOTYPES									*/
t_group_token *tokenizer(char *input);
int token_ended(char *input,int start_token, int i);
void add_new_token(t_token *new_token, t_group_token *all_token);
int find_next_start_token(char *input, int i, int token_type);
int no_more_token(int start_token, char *input);
char *delete_border_ifs(char *input);
int is_special(char *line, int i);
int	is_ifs(char c);
int is_quoted(char *input, int start_token, int i);
int	is_quote(char c);
#endif