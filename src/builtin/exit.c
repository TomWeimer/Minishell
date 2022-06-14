/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:47:35 by tweimer           #+#    #+#             */
/*   Updated: 2022/06/14 11:37:31 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_number(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

void	parse_args(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (is_number(args[i]))
		{
			write(2, "exit\n", 6);
			write_error(args[i], "exit: ", EXIT_NUM_ERROR);
			clean_shell();
			exit(255);
		}
		i++;
	}
}

void	ft_exit(t_command *cmd, int print)
{
	int	argc;

	argc = ft_tablen(cmd->args);
	parse_args(cmd->args);
	if (argc == 1)
	{
		clean_shell();
		if (print == 1)
			write(2, "exit\n", 6);
		exit(0);
	}
	else if (argc == 2)
	{	
		g_data.exit_status = ft_atoi(cmd->args[1]);
		clean_shell();
		if (print == 1)
			write(2, "exit\n", 6);
		exit(g_data.exit_status);
	}
	write_error(NULL, "exit: ", EXIT_ARG_ERROR);
	g_data.exit_status = 1;
}
