/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:34:53 by tchappui          #+#    #+#             */
/*   Updated: 2022/06/06 15:32:48 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sub_system/terminal.h"
#include "minishell.h"

//	Before the "execution" of an here_document, SIGINT
//	need to be able to end the process when encountering him
void	signal_here_document(int signal)
{
	(void)signal;
	g_data.exit_status = 1;
	write(1, "\n", 1);
	exit(1);
}
