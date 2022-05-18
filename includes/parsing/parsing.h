#ifndef PARSING_H
# define PARSING_H

// librairies:
# include <readline/readline.h>
# include <readline/history.h>

// headers:
# include "../minishell.h"
# include "parsing/tokens.h"

// define:
# define	NONE	0

# define	NO		0
# define	YES		1

# define	START	0
# define	STOP	1

# define	ENDED	3

# define	OK		1
# define	ERROR	0
# define QUOTE_ERROR "The syntax is false the brackets aren't in par!\n"

// prototypes:
int				is_ifs(char c);
int				is_special(char *line, int i);
int				is_quote(char c);
int				is_quoted(char *input, int start_token, int i);
int				token_is_redirection(int token_type);
int				token_is_operator(int token_type);
int				no_more_token(int start_token, char *input);
int				token_ended(char *input,int start_token, int i);
int				find_next_start_token(char *input, int i, int token_type);
int				token_attribution(t_group *token_group);
void			add_new_token(t_token *new_token, t_group *all_token);
int				check_token_quote(t_group *all_tokens);
t_group	*init_all_tokens(void);

#endif