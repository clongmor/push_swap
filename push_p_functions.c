#include "swap.h"

void	push_pa(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pa\n", 3);
	update_index(a);
	update_index(b);
}

void	push_pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
	update_index(a);
	update_index(b);
}