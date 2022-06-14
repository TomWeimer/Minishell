/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:46:52 by tchappui          #+#    #+#             */
/*   Updated: 2022/06/07 15:29:43 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include	"libft.h"
# include	"execution/command.h"
# include	<stdio.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}t_list;

typedef struct s_env
{
	t_list	*list;
	t_list	*temp;
}t_env;

t_list	*ft_lstnew(char *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	printlst(t_list *lst);
t_list	*ft_lstreplace(t_list *lst, char *content);
int		ft_strdcmp(char *s1, char *s2, char d);
void	ft_addenv(t_env *env, t_list *list, char *str);
void	ft_env(t_list **env, char **envp);
void	printenv(t_list *lst);
void	ft_unset(t_env *env, char **args);
void	ft_export(t_env *env, t_list *list, t_command *cmd);
void	addexport(char *args, t_env *env);
void	add_export(char *args, t_list *list, t_list *temp);
void	addexport_equal(t_list *list, char *str);
char	**ft_remplaceargs(char **args, t_env *env);
int		ft_lstlen(t_list *lst);
void	clean_env(t_list *lst);

#endif