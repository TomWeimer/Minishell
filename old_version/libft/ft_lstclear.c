#include "libft.h"
void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *actual;
    t_list *to_delete;

    if (lst ==  NULL || del == NULL)
        return;
    actual = *lst;
    while(actual != NULL)
    {
        to_delete = actual;
        actual = actual->next;
        del(to_delete->content);
        free(to_delete);
    }
    *lst = NULL;
}