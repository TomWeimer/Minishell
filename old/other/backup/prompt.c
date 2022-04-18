 
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:33:54 by tchappui          #+#    #+#             */
/*   Updated: 2022/03/17 18:32:03 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "minishel.h"

//fonction qui va chercher le chemin

//fonction qui les relies avec un tab

//fonction qui grep la ligne du "USER="
char *ft_grep_user(char **envp)
{
	int	i;

	i = 0;
	while(envp)
	{
		if (ft_strncmp("USER=", envp[i], 5) == 0)
			return(envp[i] + 5);
		i++;
	}
	return (NULL);
}

void	ft_prompt(char **envp)
{
	char	*ret;
	static char	*env;
	
	//if (env == NULL)			test
		env = ft_grep_user(envp);
	// while(1)			test
	// {
	// 	ret = readline(env);
	// 	ft_ctrl();
	// 	//printf("%s\n", ret);
	// }
}