/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:46:04 by tweimer           #+#    #+#             */
/*   Updated: 2022/06/07 14:10:56 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution/execution.h"

// delete the quotes
void	delete_quotes(t_token *actual)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strdup(actual->word);
	free(actual->word);
	actual->word = NULL;
	actual->word = ft_substr(tmp, 1, ft_strlen(tmp) - 2);
	free(tmp);
	tmp = NULL;
}

// Find if there are quotes in the token content if yes delete them
int	manage_quotes(t_group *token_group)
{
	t_token	*actual;

	actual = token_group->first;
	while (actual != NULL)
	{
		if (actual->word != NULL && is_quote(actual->word[0]) != NONE)
		{
			delete_quotes(actual);
		}
		actual = actual->next;
	}
	return (OK);
}

// find the dollar in the token
int	chr_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] != 0)
			return (YES);
		i++;
	}
	return (NO);
}

// Check if the content are not in simple quotes, if they
//	are find if there is an environement variabale $ if yes
//	call the function to replace the $variable by it's content
void	remplace_content(t_group *all_token)
{
	t_token	*actual;

	if (all_token == NULL || all_token->first == NULL)
		return ;
	actual = all_token->first;
	while (actual != NULL)
	{
		if (actual->word != NULL && actual->word[0] != '\'')
		{
			while (chr_dollar(actual->word) == YES)
			{
				actual->word = replace_dollar(actual->word, g_data.env,
						g_data.exit_status);
				if (actual->word == NULL)
					break ;
			}
		}
		actual = actual->next;
	}
}

//	We replace the content of the tokens such as quotes or 
//	environnement variables
int	expansion_arguments(t_group *token_group)
{
	remplace_content(token_group);
	if (manage_quotes(token_group) == ERROR)
		return (ERROR);
	return (OK);
}
