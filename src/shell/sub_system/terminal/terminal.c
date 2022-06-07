/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:44:24 by tweimer           #+#    #+#             */
/*   Updated: 2022/06/06 15:09:28 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sub_system/terminal.h"

// Set the settings of the terminal, as such as when pressing
// a control character the charcter is not echoed by the shell.
// Example: CTRL-C doesn't output "^C"
void	set_terminal_settings(void)
{
	int			actual_settings;
	t_terminal	config;

	actual_settings = tcgetattr(STDIN_FILENO, &config);
	config.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, actual_settings, &config);
}

// 1. Keep a copy of the standard file descriptor of the output and the input
// 2. Zero initialization of the global structure's variables
void	set_global_struct(void)
{
	g_data.stdin_fd = dup(STDIN_FILENO);
	g_data.stdout_fd = dup(STDOUT_FILENO);
	g_data.exit_status = 0;
	g_data.pid = 0;
	g_data.last_pid = 0;
	g_data.all_commands = NULL;
	g_data.all_tokens = NULL;
	g_data.binary_tree = NULL;
	g_data.input = NULL;
}

// Initialize the necessary information to the execution of the shell
// 1. Set the defaul values of the global structure called g_data
// 2. Handle the signals such as CTRL-C, ...
// 3. Calibrate some setting of the terminal
void	init_terminal(void)
{
	set_global_struct();
	block_signals_from_keyboard();
	set_terminal_settings();
}
