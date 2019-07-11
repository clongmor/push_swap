#include "/sgoinfre/clongmor/libft/libft.h"
#include <stdio.h>

/*
** assume there is a head node with a NULL value as a list placeholder
** list should be in double pointer form so it can be directly edited
*/

void    ps_swap(t_list **lsta)
{
    t_list  *tmp1;
    t_list  *tmp2;

    if (!(*lsta) || ((*lsta)->next == NULL))
    {
        printf("not proper input!\n");
        return ;
    }
    tmp1 = *lsta; //tmp empty head
    *lsta = (*lsta)->next; //move one space along in the list
    tmp2 = *lsta; //tmp2 is first position.
    *lsta = (*lsta)->next; // move to position 2
    tmp1->next = *lsta; // head node points to position 2
    tmp2->next = (*lsta)->next; // position 1 points to position 3 (as well as pos 2)
    (*lsta)->next = tmp2; //position 2 points to position 1
    *lsta = tmp1;
    while (*lsta)
    {
        printf("lsta contains: %s with size: %zu\n", (*lsta)->content, (*lsta)->content_size);
        *lsta = (*lsta)->next;
    }
    *lsta = tmp1;
}

int main(void)
{
    const char  b[6] = "hello";
    const char  c[8] = "heyhey!";
    size_t  b_size = 6;
    size_t  c_size = 8;
    t_list  **lsta;
    t_list  **head;
    
    lsta = malloc(sizeof(t_list*));
    *lsta = ft_lstnew(NULL, 0);
    printf("just made an empty node\n");
    ft_lstaddtail(lsta, (ft_lstnew(b, b_size)));
    printf("just added node 1\n");
    ft_lstaddtail(lsta, (ft_lstnew(c, c_size)));
    printf("just added node 2\n");
    ps_swap(lsta);
    head = lsta;
    while (*lsta)
    {
        printf("lsta contains: %s with size: %zu\n", (*lsta)->content, (*lsta)->content_size);
        *lsta = (*lsta)->next;
    }
    lsta = head;
    return (0);
}