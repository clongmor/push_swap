#include "swap.h"

void		len_3(t_stack **stack_a)
{
	t_stack *head_a;
	t_stack	*a_head;

	head_a = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	if (((*stack_a)->value) > (*stack_a)->next->value)
	{
		if ((*stack_a)->value > (*stack_a)->next->next->value)
		{
			if ((*stack_a)->next->value > (*stack_a)->next->next->value)
			{
				sa(stack_a);
				rra(stack_a);
				write(1, "sa\n", 3);
				write(1, "rra\n", 4);
			}
			else
			{
				ra(stack_a);
				write(1, "ra\n", 3);
			}
		}
		else
		{
			sa(stack_a);
			write(1, "sa\n", 3);
		}
	}
	else if ((*stack_a)->value > (*stack_a)->next->next->value)
	{
		rra(stack_a);
		write(1, "rra\n", 4);
	}
	else
	{
		sa(stack_a);
		ra(stack_a);
		write(1, "sa\n", 3);
		write(1, "ra\n", 3);
	}
	(*stack_a) = head_a;
}