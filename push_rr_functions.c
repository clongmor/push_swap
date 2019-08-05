#include "swap.h"

void	push_rra(t_stack **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
	update_index(a);
}

void	push_rrb(t_stack **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
	update_index(b);
}

void	push_rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	update_index(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
	update_index(b);
}