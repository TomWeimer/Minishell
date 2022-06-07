/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:11:29 by tchappui          #+#    #+#             */
/*   Updated: 2022/06/05 22:11:45 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

// define:
# define MALLOC_ERROR	"ERROR: failed to allocate memory !\n"
# define MSG_NOT_FOUND	"no such file or directory"
# define MSG_DENIED		"permission denied"
# define NEWLINE 		"\n"
# define CMD_NOT_FOUND	"command not found"
# define UNSET_ERROR		"not a valid identifier"
# define EXPORT_ERROR	"not a valid identifier"
# define EXIT_NUM_ERROR	"numeric argument required"
# define EXIT_ARG_ERROR	"too many arguments"

// prototypes:
void	write_syntax_token_error(int token_type);
void	write_error(char *message_extra, char *command, char *error_message);
#endif