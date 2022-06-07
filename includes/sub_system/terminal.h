/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:11:55 by tchappui          #+#    #+#             */
/*   Updated: 2022/06/05 22:56:10 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H

// librairies:
# include <termios.h>
# include <signal.h>
# include <readline/readline.h>
// headers:
# include "../minishell.h"

// define:
typedef struct termios		t_terminal;
typedef struct sigaction	t_sigaction;

// prototypes:
void	block_signals_from_keyboard(void);
void	rl_replace_line(const char *text, int clear_undo);
#endif