/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:33:54 by tchappui          #+#    #+#             */
/*   Updated: 2022/03/21 17:57:15 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft/libft.h"
#include "minishel.h"
pid_t g_process_pid = 0;
//fonction qui va chercher le chemin

//fonction qui les relies avec un tab

//fonction qui grep la ligne du "USER="

void ft_test (int sig)
{
	char **null;

//	printf("%d\n", sig);
	if (sig == 2)
	{
		if (g_process_pid > 0)
		{
			kill (g_process_pid, SIGINT);
		}
	}
	if (sig == 3)
	{
		exit(0);
		//printf("\n");
		//ft_prompt(null);
	}
}

char	*ft_testpromp(char *prompt)
{
	//printf("%s\n", prompt);
	prompt = ft_strjoin("->  ", prompt);
	prompt = ft_strjoin(prompt, " ❤️ ");
	//printf("%s\n", prompt);
	return (prompt);
}
char *ft_grep_user(char **envp)
{
	int	i;

	i = 0;
	while(envp)
	{
		if (ft_strncmp("USER=", envp[i], 5) == 0)
			return(envp[i] + 5);
		i++;
	}
	return (NULL);
}


void	ft_prompt(char **envp)
{
	char	*ret;
	static char	*env;
	int status;
	
	if (env == NULL)
	{
		env = ft_grep_user(envp);
		//printf("%s\n", ret);
		env = ft_testpromp(env);
		//ft_strlen(ret);
	}
	signal(SIGQUIT, ft_test);
	
	// while(1)			test
	// {
	// ft_putstr_fd("-> ", 0);
	// ft_putstr_fd(env, 0);

	
	// ft_putstr_fd(" ❤️	", 0);
	while (ret)
	{
		
		ret = readline(env);
		if (ret == NULL)
			{
				free(ret);
				return ;
			}
		pid_t out = fork();
		if (out == 0)
		{
			printf("%s", ret);
		}
		else
		{
			signal(SIGINT, ft_test);
			g_process_pid = out;
			wait(NULL);
			g_process_pid = 0;
		}
		//ft_ctrl();
		
	}
	//printf("%s\n", ret);
}


int	main (int argc, char **argv, char **envp)
{
//	ft_ctrl(envp);
	ft_prompt(envp);
}
