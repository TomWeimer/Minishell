/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:45:08 by tweimer           #+#    #+#             */
/*   Updated: 2022/06/06 16:19:06 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"

// 1.	Allocate memory for a token
// 2.	If no errors were encountered, we assign the type of the token
//		if the token is not an operator, the type of the token will be word
t_token	*init_token(char *input, int start)
{
	t_token	*new_token;
	int		token_type;

	new_token = malloc(sizeof(t_token));
	if (new_token == NULL)
	{
		write(2, MALLOC_ERROR, 35);
		exit(EXIT_FAILURE);
	}
	token_type = is_special(input, start);
	if (token_type != NONE)
		new_token->type = token_type;
	else
		new_token->type = WORD;
	new_token->word = NULL;
	return (new_token);
}

//	Create the token at this point the proprieties of a token are WORD
//	or some operator like PIPE, AND, ...
// 1.	Initialize the token
// 2.	if the token is a word we keep it's content into token->word	
t_token	*create_token(char *input, int start, int end)
{
	t_token	*token;

	token = init_token(input, start);
	if (token->type == WORD)
		token->word = ft_substr(input, start, end - start);
	return (token);
}

// 1.	Check if there's no more token to create, if YES
//		put back the static variable that is crucial to pasrse the input
//		to 0.
// 2.	Loop around the input until we encounter the end of a token
// 3.	If the end of a token is encountered, we create it
// 4.	In some case the last token need to be created.
// 5.	Before returning the token, we find the start of the next token
//		in start_token
t_token	*get_token(char *input)
{
	int			i;
	t_token		*token;
	static int	start_token = 0;

	if (no_more_token(start_token, input) == YES)
	{
		start_token = 0;
		return (NULL);
	}
	token = NULL;
	i = start_token;
	while (input[i] != '\0' && token == NULL)
	{
		if (token_ended(input, start_token, i))
			token = create_token(input, start_token, i + 1);
		i++;
	}
	if (input[i] == '\0' && token == NULL)
		token = create_token(input, start_token, i);
	start_token = find_next_start_token(input, i, token->type);
	return (token);
}

// The container of the tokens is now created we now need to create the tokens
//	1.	Loop while there's still a token to create
//	2.	The function get_token create every token
//	3.	Put the new token after the previous one in all_tokens
void	generate_tokens(char *input, t_group *all_tokens)
{
	int		looping;
	t_token	*new_token;

	looping = START;
	while (looping != STOP)
	{
		new_token = get_token(input);
		add_new_token(new_token, all_tokens);
		if (new_token == NULL)
			looping = STOP;
	}
}

// The input is received as a string, we need to separate the different
// parts of that string into elements with different properties (tokens)
// 1.	Initialize all_tokens, that is a pointer on the first token
// 2.	Called the function to generate the tokens of all_tokens
// 3.	Attribute specific roles to the tokens that aren't operator
// 4. 	Keep a pointer on the tokens, to free them when the user exit the shell
//		to avoid leaks
t_group	*tokenizer(char *input)
{
	t_group	*all_tokens;

	all_tokens = init_all_tokens();
	generate_tokens(input, all_tokens);
	if (all_tokens != NULL && check_token_quote(all_tokens) == ERROR)
	{
		return (NULL);
	}
	token_attribution(all_tokens);
	g_data.all_tokens = all_tokens;
	return (all_tokens);
}
