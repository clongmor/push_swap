#include "swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*first;

	head = (*stack);
	first = (*stack)->next;
	if (!(head->next) || !(head->next->next))
		return ;
	head->next = (*stack)->next->next;
	while (head->next != NULL)
	{
		head = head->next;
	}
	head->next = first;
	first->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	update_index(a);
}

void	rb(t_stack **b)
{
	rotate(b);
	update_index(b);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}