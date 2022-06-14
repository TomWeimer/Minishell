/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:49:08 by tweimer           #+#    #+#             */
/*   Updated: 2022/06/14 15:07:22 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"

int	token_is_redirection(int token_type)
{
	if (token_type == DLESS || token_type == LESS || token_type == DGREAT)
		return (YES);
	else if (token_type == MORE)
		return (YES);
	return (NO);
}

int	token_is_operator(int token_type)
{
	if (token_type == AND_IF || token_type == OR_IF || token_type == PIPE)
		return (YES);
	return (NO);
}

int check_pipe(t_group* all_token)
{
	t_token *actual;

	if (all_token == NULL && all_token->first == NULL)
		return (NO);
	actual = all_token->first;
	if (actual != NULL && token_is_operator(actual->type))
		return (NO);
	while (actual != NULL)
	{
		if (actual != NULL &&
			(token_is_operator(actual->type) || token_is_redirection(actual->type))
			&& actual->next == NULL)
			return (NO);
		actual = actual->next;
	}
	return (YES);
}
