#include "swap.h"

//take in list, know how many numbers in list. split total numbers in half 
//(rra/ra decision line). determine max and min and thus range of numbers.
//split into 5 groups and create group ranges. find first number in bottom
//group from top - pointer to that. find first number in bottom group from bottom
//pointer to that too. copmare positions, and either rra/ra and push to b.
//need a function to return how many rotations each one needs??
// repeat process with the list over and over until no more numbers in that
//range left in list a. move to next range and repeat the process with all
//ranges until list a is empty. then find biggest number in list b, rra/ra
//to get that number to the top and push to a, repeat until list b is empty.

void	len_100(t_stack **a, t_stack **b, int argv)
{
	int range;
	int max;
	int	range_p;
	t_stack	*group_top;
	t_stack	*group_bot;
	t_stack	*a_first;

	a_first = (*a)->next;
	max = max_num(*a);
	range = (range_num(max, min_num(*a)) + 1)/5;
	range_p = range;
	while ((*a)->next != NULL)
	{
		while (a_first != NULL)
		{
			group_top = NULL;
			if (a_first->value < range)
			{
				group_top = a_first;
				break;
			}
			a_first = a_first->next;
		}
		if (group_top != NULL)
			while(a_first != NULL)
			{
				if (a_first->value < range)
					group_bot = a_first;
				a_first = a_first->next;
			}
		else
		{
			range += range_p;
			a_first = (*a)->next;
			continue ;
		}
		a_first = (*a)->next;
		if (((lstlength(a_first)) - group_bot->index) < group_top->index)
		{
			while (a_first->value != group_bot->value)
			{
				push_rra(a);
				a_first = (*a)->next;
			}
			push_pb(a, b);
			a_first = (*a)->next;
		}
		else 
		{
			while (a_first->value != group_top->value)
			{
				push_ra(a);
				a_first = (*a)->next;
			}
			push_pb(a, b);
			a_first = (*a)->next;
		}
	}
	while ((*b)->next != NULL)
	{
		max = max_index(*b);
		a_first = (*b)->next;
		if (((lstlength(a_first)) - max) < lstlength(a_first)/2)
		{
			max = max_num(*b);
			while (a_first->value != max)
			{
				push_rrb(b);
				a_first = (*b)->next;
			}
			push_pa(b, a);
			a_first = (*b)->next;
		}
		else 
		{
			max = max_num(*b);
			while (a_first->value != max)
			{
				push_rb(b);
				a_first = (*b)->next;
			}
			push_pa(b, a);
			a_first = (*b)->next;
		}
	}
}