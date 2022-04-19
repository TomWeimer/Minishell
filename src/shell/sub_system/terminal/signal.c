#include "sub_system/terminal.h"

void	signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		rl_on_new_line();
		write(2, "\n", 1);
		rl_replace_line("", 1);
		rl_redisplay();
	}
	else if (signal == SIGTERM)
	{
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		exit(EXIT_SUCCESS);
	}
	else if (signal == SIGQUIT)
	{
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		return ;
	}
	return ;
}

void	block_signals_from_keyboard(void)
{
	t_sigaction	sa;

	sa.sa_handler = &signal_handler;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGTERM, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}
