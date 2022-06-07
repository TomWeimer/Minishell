/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:20:05 by tweimer           #+#    #+#             */
/*   Updated: 2022/06/05 21:33:24 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"

int	is_quote(char c)
{
	if (c == '\'')
		return (SQUOTED);
	else if (c == '\"')
		return (DQUOTED);
	return (NONE);
}

int	is_quoted(char *input, int start_token, int i)
{
	int	start_quote;
	int	end_quote;

	if (start_token == i)
		return (NO);
	start_quote = is_quote(input[start_token]);
	end_quote = is_quote(input[i]);
	if (start_quote != NONE && start_quote == end_quote)
		return (ENDED);
	if (start_quote == NONE && end_quote == NONE)
		return (NO);
	return (YES);
}

int	check_quote(char *word)
{
	int	i;
	int	j;
	int	quote1;
	int	quote2;

	i = 0;
	j = ft_strlen(word);
	while (word[i] && quote1 == NONE)
	{
		quote1 = is_quote(word[i]);
		i++;
	}
	while (word[j] && quote2 == NONE && j < i)
	{
		quote2 = is_quote(word[j]);
		j--;
	}
	if (quote1 != NONE || quote2 != NONE)
		return (FAILED);
	return (OK);
}

int	check_token_quote(t_group *all_tokens)
{
	t_token	*actual;
	int		quote[2];

	actual = all_tokens->first;
	while (actual != NULL)
	{
		if (actual != NULL && actual->word != NULL)
		{
			quote[0] = is_quote(actual->word[0]);
			if (ft_strlen(actual->word) > 1)
				quote[1] = is_quote(actual->word[ft_strlen(actual->word) - 1]);
			else
				quote[1] = NONE;
			if (quote[0] != quote[1])
			{
				if (!check_quote(actual->word))
				{
					write(2, QUOTE_ERROR, 48);
					return (ERROR);
				}
			}	
		}
		actual = actual->next;
	}
	return (OK);
}
