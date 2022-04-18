#include "../../includes/env.h"
#include <stdlib.h>
//#include "../../includes/minishell.h"

void	ft_env(t_list **env, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != 0)
	{
		ft_lstadd_back(env, ft_lstnew(envp[i]));
		i++;
	}
}

char	*ft_compart(char *arg, t_list *env, t_list *temp)
{
	int	i;

	ft_strcat(arg, "=");
	i = ft_strlen(arg);
	while (env != NULL)
	{
		if (ft_strdcmp(arg, env->content, '=') == 0)
			return (env->content + i);
		env = env->next;
	}
	while (temp != NULL)
	{
		if (ft_strdcmp(arg, temp->content, '=') == 0)
			return (temp->content + i);
		temp = temp->next;
	}
	return (NULL);
}

char	**ft_test(char **args, int i, int j, t_env *env)
{
	char	*retenv;
	int		n;

	n = 0;
	retenv = ft_compart(args[i] + j + 1, env->list, env->temp);
	if (retenv != NULL)
	{
		while (retenv[n] != 0)
		{
			args[i][j] = retenv[n];
			j++;
			n++;
		}
		args[i][j] = 0;
	}
	else
		args[i][j] = 0;
	return (args);
}

char	**ft_remplaceargs(char **args, t_env *env)
{
	int		i;
	int		j;
	char	**t;

	i = 0;
	while (args[++i] != NULL)
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == '$')
			{
				t = ft_test(args, i, j, env);
				j++;
			}
			j++;
		}
	}
	return (t);
}
