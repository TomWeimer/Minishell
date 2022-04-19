#include "execution/execution.h"

void	print_to_outfiles(char *str, t_command *cmd)
{
	t_redirection	*actual;
	t_redirection	*last;

	last = NULL;
	actual = NULL;
	if (str == NULL)
		return ;
	if (cmd->output != NULL)
	{
		redirection_files(cmd);
		actual = cmd->output;
		while (actual != NULL)
		{
			last = actual;
			actual = actual->next;
		}
		ft_putstr_fd(str, last->fd);
	}
	if (cmd->output != NULL)
		close(last->fd);
	else if (cmd->args != NULL)
		ft_putstr_fd(str, STDOUT_FILENO);
}

int	is_builtin(char *str)
{
	char	**builtin;
	int		i;

	i = 0;
	builtin = malloc ((4 + 1) * sizeof(char *));
	builtin[0] = "echo";
	builtin[1] = "cd";
	builtin[2] = "pwd";
	builtin[3] = "exit";
	builtin[4] = NULL;
	while (builtin[i])
	{
		if (ft_strcmp(str, builtin[i]) == 0)
		{
			free(builtin);
			builtin = NULL;
			return (i + 1);
		}
		i++;
	}
	free(builtin);
	builtin = NULL;
	return (0);
}

void	execute_builtin(t_tree *node, int ok)
{
	replace_input(node->cmd);
	if (ok == CMD_ECHO)
	{
		ft_echo(node->cmd);
	}
	else if (ok == CMD_CD)
	{
		ft_cd(node->cmd);
	}
	else if (ok == CMD_PWD)
	{
		ft_pwd(node->cmd);
	}
	else if (ok == CMD_EXIT)
	{
		ft_exit(node->cmd);
	}
}

int	execute_cmd(t_tree *node)
{
	int	ok;

	ok = 0;
	if (node->cmd->args != NULL)
		ok = is_builtin(node->cmd->args[0]);
	if (ok <= 0)
	{
		replace_input(node->cmd);
		redirection_files(node->cmd);
		if (node->cmd->args != NULL)
			write(2, CMD_NOT_FOUND, 25);
		node->cmd->status = 0;
		return (0);
	}
	else
	{
		execute_builtin(node, ok);
		node->cmd->status = 1;
	}
	return (1);
}

void	shell_execution(t_group *all_token, t_command **all_command)
{
	t_tree	*root;

	manage_here_doc(all_command);
	root = binary_tree(all_token, all_command);
	manage_node_execution(root);
	clean_tree(root);
	if (root != NULL)
		root = NULL;
}
