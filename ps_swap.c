#include "/sgoinfre/clongmor/libft/libft.h"
#include <stdio.h>

/*
** takes in a double pointer to list, switches around the pointers
** for the first two links, to swap the first two items in a stack
** and returns nothing.
*/

void ps_swap(t_list **lsta)
{
    t_list *tmp;
    t_list *lst;

    if (!(*lsta) || ((*lsta)->next == NULL))
    {
        printf("not proper input!\n");
        return ;
    }
    (tmp) = (*lsta);
    (lst) = (*lsta)->next->next;

    (*lsta) = (*lsta)->next;
    (*lsta)->next = (tmp);
    tmp->next = lst; 
}