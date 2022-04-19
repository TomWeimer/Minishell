
typedef struct s_list
{
	char *content;
	struct s_list *next;
}t_list;

typedef struct s_env
{
	int	envsize;
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
void	printenv(t_list *env, int size);
void	ft_unset(t_env *env, char **args);
void	ft_export(t_env *env, t_list *list, char **args);
char	**ft_remplaceargs(char **args, t_env *env);