#include "swap.h"

void		len_3(t_stack **stack_a)
{
	t_stack *first;
	t_stack	*second;
	t_stack	*third;

	first = (*stack_a)->next;
	second = (*stack_a)->next->next;
	third = (*stack_a)->next->next->next;
	if (first->value > second->value)
	{
		if (first->value > third->value)
		{
			if (second->value > third->value)
			{
				push_sa(stack_a);
				push_rra(stack_a);
			}
			else
				push_ra(stack_a);
		}
		else
			push_sa(stack_a);
	}
	else if (first->value > third->value)
		push_rra(stack_a);
	else
	{
		push_sa(stack_a);
		push_ra(stack_a);
	}
}