/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:10:12 by tweimer           #+#    #+#             */
/*   Updated: 2022/03/25 18:10:58 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int	main(int argc, char *argv[], char *envp[])
{
	(void)envp;
	(void)argc;
	(void)argv;
	kill(0, SIGTERM);
}
