#include "sub_system/terminal.h"
# include "minishell.h"
void new_prompt(int sig)
{
	(void)sig;
	g_print = 130;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();

}

void no_prompt(int sig)
{
	(void)sig;
	g_print = 130;
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
