#include "libft.h"
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_list;
    t_list *first;

	if (!del||!f)
		return(NULL);
	first = NULL;
	while(lst)
	{
		if (!(new_list = ft_lstnew((*f)(lst->content))))
		{
			while(first)
			{
				new_list = first->next;
				(*del)(first->content);
				free(first);
				first = new_list;
			}
		lst = NULL;
		return(NULL);
		}
		ft_lstadd_back(&first, new_list);
		lst = lst->next;
   	}
    return (first);
}

