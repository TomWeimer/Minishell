/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:44:14 by tweimer           #+#    #+#             */
/*   Updated: 2022/05/27 13:44:19 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "sub_system/terminal.h"
# include "minishell.h"

void new_prompt(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();

}
void reap_child(int sig)
{
	(void)sig;
    int status;
    waitpid(-1, &status, WNOHANG);
}

void	signal_here_document(int signal)
{
	(void)signal;
	g_data.exit_status = 130;
	write(1, "\n", 1);
	exit(130);
}

void no_prompt(int sig)
{
	(void)sig;
	write(1, "\0", 1);
}

void exit_minishell(int sig)
{
	(void)sig;
	exit(EXIT_SUCCESS);
}

void handler_child(int sig)
{
	if (sig == SIGINT)
	{
		exit(0);
	}
}

void	block_signals_from_keyboard(void)
{
	signal(SIGINT, new_prompt);
	signal(SIGQUIT, SIG_IGN);
}
