/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:44:24 by tweimer           #+#    #+#             */
/*   Updated: 2022/05/27 16:08:44 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sub_system/terminal.h"

// Summary: Set the settings of the terminal, as such as when pressing
//			a control character the charcter is not echoed by the shell
// example: CTRL-C doesn't output ^C
void	set_terminal_settings(void)
{
	int			actual_settings;
	t_terminal	config;

	actual_settings = tcgetattr(STDIN_FILENO, &config);
	config.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, actual_settings, &config);
}

// Summary: Call the functions bellow to initialize the terminal settings
void	init_terminal(void)
{
	g_data.stdin_fd = dup(STDIN_FILENO);
	g_data.stdout_fd = dup(STDOUT_FILENO);
	g_data.exit_status = 0;
	g_data.pid = 0;
	g_data.here_doc = NULL;
	g_data.last_pid = 0;
	block_signals_from_keyboard();
	set_terminal_settings();
}
