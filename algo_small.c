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

void	len_5(t_stack **a, t_stack **b, int argv)
{
	t_stack	*a_first;
	int		min_ind;
	int		min;
	int		i;

	i = 2;
	if (argv == 5)
		i = 1;	
	a_first = (*a)->next;
	while (i > 0)
	{
		min = min_num(*a);
		if((min_ind = min_index(*a)) > 3)
			while (a_first->value != min)
			{
				push_rra(a);
				a_first = (*a)->next;
			}
		else while (a_first->value != min)
		{
			push_ra(a);
			a_first = (*a)->next;
		}
		push_pb(a, b);
		a_first = (*a)->next;
		i--;
	}
	len_3(a);
	push_pa(b, a);
	if (argv == 6)
		push_pa(b, a);
}