#include "swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	head = (*stack);

	if (!(head->next) || !(head->next->next))
		return ;
	while (head->next != NULL)
	{
		head = head->next;
	}
	last = head;
	head = *stack;
	while (head->next->next != NULL)
	{
		head = head->next;
	}
	head->next = NULL;
	last->next = (*stack)->next;
	(*stack)->next = last;
}
void	rra(t_stack **a)
{
	rev_rotate(a);
	update_index(a);
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
	update_index(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	update_index(a);
	rev_rotate(b);
	update_index(b);
}