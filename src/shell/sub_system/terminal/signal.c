/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:44:14 by tweimer           #+#    #+#             */
/*   Updated: 2022/06/06 15:29:53 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sub_system/terminal.h"
#include "minishell.h"

//  Readline wait for the user to press enter, it also
//	handle the signals by default, so we have no other choice, than
//	beginning a new line, replacing the buffer, by nothing but a '\0'
//	and redisplaying the prompt.
void	new_prompt(int sig)
{
	(void)sig;
	g_data.exit_status = 1;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
}

//  1.	Assign SIGINT to new_promp, when encountering 
//	this signal the function (new_prompt) will be called
//  2. Ignore the signal SIGQUIT
void	block_signals_from_keyboard(void)
{
	signal(SIGINT, new_prompt);
	signal(SIGQUIT, SIG_IGN);
}

// Signal handler of a child in a running process, for SIGQUIT
static void	quit_process(int signal)
{
	(void)signal;
	g_data.exit_status = 131;
	write(2, "Quit: 3\n", 8);
}

// Signal handler of a child in a running process, for SIGINT
static void	interrupt_process(int signal)
{
	(void)signal;
	g_data.exit_status = 130;
	write(1, "\n", 1);
}

//  During the execution of the command line, the signal need to be changed
// 	1. If SIGINT	-> interrupt_process()
//	2. If SIGQUIT	-> quit_process()
void	exec_signals(void)
{
	signal(SIGINT, interrupt_process);
	signal(SIGQUIT, quit_process);
}
