/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:45:02 by tweimer           #+#    #+#             */
/*   Updated: 2022/05/27 13:45:03 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"

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

int	no_more_token(int start_token, char *input)
{
	if (start_token >= (int)ft_strlen(input))
		return (YES);
	return (NO);
}

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

int	token_ended(char *input, int start_token, int i)
{
	int	quote;

	quote = is_quoted(input, start_token, i);
	if (quote == ENDED)
		return (YES);
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
