#include "swap.h"

void	push_sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
	update_index(a);
}

void 	push_sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
	update_index(b);
}

void	push_ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}