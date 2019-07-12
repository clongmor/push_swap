#include "/sgoinfre/clongmor/libft/libft.h"
#include <stdio.h>

void    ps_push(t_list **lsta, t_list **lstb)
{
    t_list  *tmp_b;
    t_list  *tmp_a;

    if (!(*lstb))
    {
        printf("nothing in lstb");
        return ;
    }
    tmp_b = (*lstb)->next;
                            printf("\ntmp_b is: %s and lstb->next is %s\n", tmp_b->content, (*lstb)->next->content);
    tmp_a = (*lsta);
                            printf("tmp_a is: %s and (*lsta) is: %s\n", tmp_a->content, (*lsta)->content);
    (*lstb)->next = tmp_a;
                            printf("(*lstb)->next is: %s and tmp_a is: %s\n", (*lstb)->next->content, tmp_a->content);
    (*lsta) = (*lstb);
                            printf("(*lsta) is: %s\n", (*lsta)->content);
    (*lstb) = tmp_b;
                            printf("(*lstb) is: %s\n\n", (*lstb)->content);
}
int main(void)
{
    const char  b[6] = "hello";
    const char  c[8] = "heyhey!";
    const char  d[3] = "hi";
    size_t  b_size = 6;
    size_t  c_size = 8;
    size_t  d_size = 3;
    t_list  *lsta;
    t_list  *lstb;
    t_list  *head;
    
    lsta = malloc(sizeof(t_list));
    lstb = malloc(sizeof(t_list));
    lstb = ft_lstnew(b, b_size);
    lsta = ft_lstnew(b, b_size);
    ft_lstaddtail(&lsta, (ft_lstnew(c, c_size)));
    ft_lstaddtail(&lsta, ft_lstnew(d, d_size));
    //ft_lstaddtail(&lstb, (ft_lstnew(c, c_size)));
    head = lsta;
    while (lsta)
    {
        printf("lsta contains: %s\n", (lsta)->content);
        lsta = (lsta)->next;
    }
    lsta = head;
    head = lstb;
    if (lstb == NULL)
        printf("lstb is empty");
    else while (lstb)
    {
        printf("lstb contains: %s\n", (lstb)->content);
        if (lstb->next == NULL)
            printf("lstb only has one item\n");
        lstb = (lstb)->next;
    }
    lstb = head;
    ps_push(&lsta, &lstb);
    //ps_swap(&lsta);
    head = lsta;
    while (lsta)
    {
        printf("lsta contains: %s\n", (lsta)->content);
        lsta = (lsta)->next;
    }
    lsta = head;
    head = lstb;
    if (lstb == NULL)
        printf("lstb is empty");
    else while (lstb)
    {
        printf("lstb contains: %s\n", (lstb)->content);
        lstb = (lstb)->next;
    }
    lstb = head;
    return (0);
}