#include "../../../includes/minishell.h"
#include "../../../includes/tokens.h"
#include "../../../includes/syntax.h"
#include "../../../includes/command.h"

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
			return (i + 1);
		i++;
	}
	return (0);
}

int execute_cmd(t_treenode *node)
{
	int ok;

	ok = 0;

	if (node->cmd->args!= NULL)
		ok = is_builtin(node->cmd->args[0]);
	if (ok <= 0)
	{
		replace_input(node->cmd);	
		redirection_files(node->cmd);
		if (node->cmd->args != NULL)
			write(2, "Error: command not found\n", 25);
		node->cmd->status = 0;
		return (0);
	}
	else
	{
		replace_input(node->cmd);	
		if (node->cmd->args == NULL)
		{
			node->cmd->status = 0;
			return (0);
		}
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
		node->cmd->status = 1;
	}

		
	return (1);
}

    
void clean_tree(t_treenode *node)
{
	if (node == NULL)
        return;
	clean_tree(node->left);
	clean_tree(node->right);
    free (node);
	node = NULL;
}

void clean_cmd_redirection(t_redirection *first)
{
	t_redirection *actual;
	t_redirection *to_delete;

	to_delete = NULL;
	actual = first;
	while (actual != NULL)
	{
		to_delete = actual;
		actual = actual->next;
		if (to_delete->file_name != NULL)
			free(to_delete->file_name);
		free(to_delete);
	}
}


void clean_tokens(t_group_token *all_token)
{
	t_token *actual;
	t_token *to_delete;

	if (all_token != NULL)
	{
		to_delete = NULL;
		actual = all_token->first;
		while (actual != NULL)
		{
			to_delete = actual;
			actual = actual->next;
			if (to_delete->word != NULL)
			{
				free(to_delete->word);
				to_delete->word = NULL;
			}
			free(to_delete);
			to_delete = NULL;
		}
	}
}

void clean_input(char *input)
{
	if (input != NULL)
	{
		free(input);
		input = NULL;
	}
}

void clean_cmd_args(char **args)
{
	int i;

	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		args[i] = NULL;
		i++;
	}
}

void clean_commands(t_command **all_commands)
{
	int i;

	i = 0;
	if (all_commands != NULL)
	{
		while (all_commands[i] != NULL)
		{
			if (all_commands[i]->args != NULL)
				clean_cmd_args(all_commands[i]->args);
			if (all_commands[i]->input != NULL)
				clean_cmd_redirection(all_commands[i]->input);
			if (all_commands[i]->output != NULL)
				clean_cmd_redirection(all_commands[i]->output);
			free(all_commands[i]);
			all_commands[i] = NULL;
			i++;
		}
	}
}


void shell_execution(t_group_token *all_token, t_command **all_command)
{
	t_treenode *root;

	manage_here_doc(all_command);
	root = binary_tree(all_token, all_command);
	manage_node_execution(root);
	clean_tree(root);
	if (root != NULL)
		root = NULL;
}


	


