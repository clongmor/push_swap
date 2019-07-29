#include "swap.h"

int		main(int argv, char **argc)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*a_head;
	t_stack	*b_head;

	error_check_suite(argv, argc);
	a = create_master();
	b = create_master();
	populate_list(&a, argc);

	return (0);
}