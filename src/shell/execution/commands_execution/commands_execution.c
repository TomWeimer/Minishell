#include "execution/execution.h"
#include "environment/env.h"

int	ft_checkequal(char **args, t_env *env) // changer de places
{
	int	i;

	i = -1;
	while (args[++i] != NULL)
	{
		if (ft_strchr(args[i], '=') != NULL)
			ft_addenv(env, env->list, args[i]);
		else
			return (0);
	}
	return (9);
}

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

	i = -1;
	builtin = malloc ((7 + 1) * sizeof(char *));
	builtin[0] = "echo";
	builtin[1] = "cd";
	builtin[2] = "pwd";
	builtin[3] = "exit";
	builtin[4] = "export";
	builtin[5] = "unset";
	builtin[6] = "env";
	builtin[7] = NULL;
	while (builtin[++i])
	{
		if (ft_strcmp(str, builtin[i]) == 0)
		{
			free(builtin);
			builtin = NULL;
			return (i + 1);
		}
	}
	free(builtin);
	builtin = NULL;
	return (0);
}

void	execute_builtin(t_tree *node, int ok, t_env *env)
{
	replace_input(node->cmd);
	if (ok == CMD_ECHO)
		ft_echo(node->cmd);
	else if (ok == CMD_CD)
		ft_cd(node->cmd, env);
	else if (ok == CMD_PWD)
		ft_pwd(node->cmd);
	else if (ok == CMD_EXIT)
		ft_exit(node->cmd);
	else if (ok == CMD_EXPORT)
		ft_export(env, env->list, node->cmd);
	else if (ok == CMD_UNSET)
		ft_unset(env, node->cmd->args);
	else if (ok == CMD_ENV)
		printenv(node->cmd, env, env->list);
	ft_lastcmd(ok, env);
}

void input_redirection(t_command *cmd)
{
	if (cmd->input == NULL)
		return ;
	replace_input(cmd);
}

void output_redirection(t_command *cmd)
{
	int fd;

	if (cmd->output == NULL)
		return ;
	fd = redirection_files(cmd);
	if (fd >= 0)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

int	execute_cmd(t_tree *node, t_env *env, int type)
{
	int	ok;
	ok = 0;
	ft_wildcard(node->cmd);
	ok = ft_checkequal(node->cmd->args, env);
	if (ft_tabchr(node->cmd->args, '$') == 1)
		node->cmd->args = ft_remplaceargs(node->cmd->args, env);
	if (node->cmd->args == NULL)
		return (1);
	// DELIMITATION 1
	input_redirection(node->cmd);
	output_redirection(node->cmd);
	ok = is_builtin(node->cmd->args[0]);
	if (ok <= 0)
	{	
		if (type != PIPE)
			ok = base_builtin(node->cmd->args, env);
		else
			ok = pipe_base_builtin(node, env);
		if (ok == YES) // base builtin executer
		{
			node->cmd->status = 1;
			return (1);
		}
		else
		{
				node->cmd->status = 0;
			return (0);
		}
	}
	// DELIMITATION 2
	else
	{
		execute_builtin(node, ok, env);
		node->cmd->status = 1;
	}
	return (1);
}
/* 
int	execute_cmd(t_tree *node, t_env *env)
{
	int	ok;

	ok = 0;
	ft_wildcard(node->cmd);
	ok = ft_checkequal(node->cmd->args, env);
	if (ft_tabchr(node->cmd->args, '$') == 1)
		node->cmd->args = ft_remplaceargs(node->cmd->args, env);
	if (node->cmd->args != NULL)
		ok = is_builtin(node->cmd->args[0]);
	if (ok <= 0)
		ok = base_builtin(node->cmd->args, env);
	if (ok <= 0)
	{
		replace_input(node->cmd);
		redirection_files(node->cmd);
		node->cmd->status = 0;
		return (0);
	}
	else
	{
		execute_builtin(node, ok, env);
		node->cmd->status = 1;
	}
	return (1);
}
 */
void	shell_execution(t_group *all_token, t_command **all_command, t_env *env)
{
	t_tree	*root;

	manage_here_doc(all_command);
	root = binary_tree(all_token, all_command);
	manage_node_execution(root, env);
	clean_tree(root);
	if (root != NULL)
		root = NULL;
}
