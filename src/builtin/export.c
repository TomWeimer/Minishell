/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tweimer <tweimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:47:40 by tweimer           #+#    #+#             */
/*   Updated: 2022/06/06 10:52:46 by tweimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment/env.h"
#include "execution/execution.h"

void	printexport(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	write(1, "declare -x ", 11);
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		if (str[i] == '=' && c == 0)
		{
			write(1, "\"", 1);
			c++;
		}
		i++;
	}
	if (c == 1)
		write(1, "\"", 1);
	write(1, "\n", 1);
}

int	check_arg(char *args)
{
	int	i;

	i = 0;
	if (ft_isalpha(args[i++]) == NONE)
		return (NONE);
	while (args[i] && args[i] != '=')
	{
		if (ft_isalnum(args[i]) == NONE)
			return (NONE);
		i++;
	}
	return (YES);
}

void	export_with_args(t_command *cmd, t_env *env)
{
	int	i;

	i = 0;
	while (cmd->args[++i] != NULL)
	{
		if (check_arg(cmd->args[i]) == NONE)
		{
			write_error(cmd->args[i], "export: ", EXPORT_ERROR);
			g_data.exit_status = 1;
		}
		else
		{
			if (ft_strchr(cmd->args[i], 61) != NULL)
				addexport_equal(env->list, cmd->args[i]);
			else
				addexport(cmd->args[i], env);
			g_data.exit_status = 0;
		}
	}
}

void	ft_export(t_env *env, t_list *list, t_command *cmd)
{
	if (ft_tablen(cmd->args) == 1)
	{
		while (list != NULL)
		{
			if (ft_strdcmp(list->content, "_=", '=') != 0)
				printexport(list->content);
			list = list->next;
		}
	}
	else
		export_with_args(cmd, env);
}
