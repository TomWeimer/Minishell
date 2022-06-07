/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:45:02 by tweimer           #+#    #+#             */
/*   Updated: 2022/06/06 16:31:08 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"

// Allocate memory for all_tokens and if it fail exit the program
t_group	*init_all_tokens(void)
{
	t_group	*all_tokens;

	all_tokens = malloc(sizeof(t_group));
	if (all_tokens == NULL)
	{
		write(2, MALLOC_ERROR, 35);
		exit(EXIT_FAILURE);
	}
	all_tokens->first = NULL;
	return (all_tokens);
}

//	the start of the future token is bigger than the lenght of the
//	input it means that there's no more token
int	no_more_token(int start_token, char *input)
{
	if (start_token >= (int)ft_strlen(input))
		return (YES);
	return (NO);
}

//	To find the start of the next token we jump one character
//	if the token was composed of two character because we stopped
//	at the first one example | <- we stop here | <- but there's another
//	one
//	And then we find the start of the token after the ifs
int	find_next_start_token(char *input, int i, int token_type)
{
	if (token_type == OR_IF || token_type == AND_IF
		|| token_type == DLESS || token_type == DGREAT)
	{
		i++;
	}
	while (is_ifs(input[i]) == YES)
		i++;
	return (i);
}

// We browse through the tokens until the end and then we add the new token
void	add_new_token(t_token *new_token, t_group *all_token)
{
	t_token	*actual;

	if (new_token == NULL)
		return ;
	actual = NULL;
	if (all_token->first == NULL)
		all_token->first = new_token;
	else
	{
		actual = all_token->first;
		while (actual->next != NULL)
			actual = actual->next;
		actual->next = new_token;
	}
	new_token->next = NULL;
}

// To determine if it's the end of a token we
// 1.	We check if the token is between quote
// 2.	If it's not between quote but the next character is
//		a quote we stop the token.
// 3.	If the token is not beetwen quote we stop as soon as
//		we meet an ifs character (space, tabs,..)
//		We also stop if we encountered a special character
// 		like '|' or '&&'
int	token_ended(char *input, int start_token, int i)
{
	int	quote;

	quote = is_quoted(input, start_token, i);
	if (quote == ENDED)
		return (YES);
	if (quote == NO && is_quote(input[i + 1]))
	{
		if (is_quote(input[i]) == is_quote(input[i + 1]))
			return (NO);
		return (YES);
	}
	else if (quote == NO && is_quote(input[i]) == NO)
	{
		if (is_ifs(input[i + 1]) == YES)
			return (YES);
		else if (is_special(input, i + 1))
			return (YES);
		else if (is_special(input, i))
			return (YES);
	}
	return (NO);
}
