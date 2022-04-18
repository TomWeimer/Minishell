/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:11:14 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/25 18:12:56 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	echo(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*var;

	(void) argc;
	i = 1;
	var = NULL;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != '$')
				write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	(void)envp;
	(void)argc;
	echo(argc, argv);
}
