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
	block_signals_from_keyboard();
	set_terminal_settings();
}
