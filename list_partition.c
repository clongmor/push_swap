#include "swap.h"

int	max_num(t_stack *a)
{
	int	max;

	a = a->next;
	max = a->value;
	while (a != NULL)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	return (max);
}

int	min_num(t_stack *a)
{
	int	min;

	a = a->next;
	min = a->value;
	while (a != NULL)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

int	min_index(t_stack *a)
{
	int	min;
	int	min_index;

	a = a->next;
	min = a->value;
	min_index = a->index;
	while (a != NULL)
	{
		if (a->value < min)
		{
			min = a->value;
			min_index = a->index;
		}
		a = a->next;
	}
	return (min_index);
}

int	range_num(int max, int min)
{
	int	range;

	range = max - min + 1;
	return (range);
}

int	last_val(t_stack **a)
{
	t_stack	*lst;

	lst = (*a)->next;
	while (lst->next != NULL)
		lst = lst->next;
	return (lst->value);
}