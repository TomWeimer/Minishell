#include "environment/env.h"
#include "execution/execution.h"
#include <stdlib.h>

void	addexport(t_list *list, char *str)
{
	t_list	*newlist;

	newlist = list;
	while (list != NULL)
	{
		if (ft_strdcmp(list->content, str, '=') == 0)
		{
			free (list->content);
			list->content = ft_strdup(str);
			return ;
		}
		list = list->next;
	}
	ft_lstadd_back(&newlist, ft_lstnew(str));
}

void	ft_testa(char *args, t_list *list, t_list *temp)
{
	int	i;

	while (temp != NULL)
	{
		if (ft_strdcmp(args, temp->content, '=') == 0)
		{
			ft_lstadd_back(&list, ft_lstnew(temp->content));
			return ;
		}
		temp = temp->next;
	}
	i = 0;
	while (args[i] != '=')
		i++;
	args[i] = 0;
	ft_lstadd_back(&list, ft_lstnew(args));
}

void	add_export(char *args, t_env *env)
{
	t_list	*newenv;

	newenv = env->list;
	ft_strcat(args, "=");
	while (newenv != NULL)
	{
		if (ft_strdcmp(args, newenv->content, '=') == 0)
			return ;
		newenv = newenv->next;
	}
	ft_testa(args, env->list, env->temp);
}

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

void	ft_export(t_env *env, t_list *list, t_command *cmd)
{
	int	i;

	i = 0;
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
	{
		while (cmd->args[++i] != NULL)
		{
			if (ft_strchr(cmd->args[i], 61) != NULL)
				addexport(env->list, cmd->args[i]);
			else
				add_export(cmd->args[i], env);
		}
	}
}
