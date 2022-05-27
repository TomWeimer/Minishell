#include "minishell.h"
#include "environment/env.h"

void	newpwd(t_env *env) //met a jour la var d'env pwd
{
	char	*newpwd;
	char	*buffer;

	buffer = getcwd(NULL, 0);
	newpwd = ft_strjoin("PWD=", buffer);
	ft_addenv(env, env->list, newpwd);
	free(buffer);
	free(newpwd);
	newpwd = NULL;
	buffer = NULL;
}

void	oldpwd(t_env *env) //met a jour la var d'env oldpwd
{
	char	*newpwd;
	t_list	*oldpwd;
	char	*pwd;

	oldpwd = env->list;
	while (ft_strdcmp(oldpwd->content, "PWD=", '=') != 0)
		oldpwd = oldpwd->next;
	pwd = oldpwd->content + 4;
	newpwd = ft_strjoin("OLDPWD=", pwd);
	ft_addenv(env, env->list, newpwd);
	free(newpwd);
	newpwd = NULL;
}

void	ft_cd(t_command *cmd, t_env *env)
{
	int	user_access;

	if (cmd->args[DIRECTORY] != NULL)
	{
		user_access = access(cmd->args[DIRECTORY], F_OK | X_OK);
		if (user_access == DENIED)
			write_error(cmd->args[DIRECTORY], "cd :");
		else
		{
			chdir(cmd->args[DIRECTORY]);
			oldpwd(env);
			newpwd(env);
		}
	}
	else
		write_error(NULL, "cd :");
}