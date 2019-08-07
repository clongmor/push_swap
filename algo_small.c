#include "swap.h"

void		len_3(t_stack **stack_a)
{
	t_stack *first;
	t_stack	*second;
	t_stack	*third;

	first = (*stack_a)->next;
	second = (*stack_a)->next->next;
	third = (*stack_a)->next->next->next;
	if ((check_sorted(*stack_a)) == 1)
		return ;
	if (second != NULL && first->value > second->value)
	{
		if (third != NULL && first->value > third->value)
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

void	len_5(t_stack **a, t_stack **b)
{
	t_stack	*a_first;
	t_stack	*b_first;
	int		last;
	int	max;

	push_pb(a, b);
	push_pb(a, b);
	len_3(a);
	a_first = (*a)->next;
	b_first	= (*b)->next;
	max = max_num(*a);
	while (b_first != NULL)
	{
		last = last_val(a);
		if (b_first->value < a_first->value && b_first->value > last)
			push_pa(b, a);
		else if (b_first->value < a_first->value && b_first->value < last)
			push_rra(a);
		else if (b_first->value > max)
		{
			push_pa(a, b);
			push_ra(a);
			max = b_first->value;
		}
		else while (b_first->value > a_first->value && a_first->value != max)
		{
			push_ra(a);
			a_first = (*a)->next;
			b_first	= (*b)->next;
		}
		a_first = (*a)->next;
		b_first = (*b)->next;
	}
	a_first = (*a)->next;
	last = last_val(a);
	while (a_first->value > last)
	{
		push_rra(a);
		a_first = (*a)->next;
		last = last_val(a);
	}
}