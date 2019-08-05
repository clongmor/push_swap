#include "swap.h"

int		check_sorted(t_stack *stack_a)
{
	stack_a = stack_a->next;
	while (stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	apply_algo(int argv, t_stack **a, t_stack **b)
{
	if (argv == 4)
		len_3(a);
	//if (argv > 4 && argv < 10)
		//do something
}


int		main(int argv, char **argc)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*a_head;
	t_stack	*b_head;
	int	sorted;

	error_check_suite(argv, argc);
	a = create_master();
	b = create_master();
	populate_list(&a, argc);
	if ((sorted = check_sorted(a)) == 1)
		return (0); // how to handle if list is sorted and no instructions needed?
	apply_algo(argv, &a, &b);
	// a_head = a;
	// while (a != NULL)
	// {
	// 	printf("A: %d\n", a->value);
	// 	a = a->next;
	// }
	// a = a_head;
	// printf("\n");
	// b_head = b;
	// while (b != NULL)
	// {
	// 	printf("B: %d\n", b->value);
	// 	b = b->next;
	// }
	// b = b_head;
	return (0);
}