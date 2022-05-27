#include "libft.h"

void ft_lstadd_back(t_list **alst, t_list *new)
{
    t_list *actual;

    if (alst == NULL || new == NULL)
        return ;
    if (*alst == NULL)
    {
        *alst = new;
        return ;
    }
    actual = *alst;
    while(actual->next != NULL)
        actual = actual->next;
    actual->next = new;
    return ;
}