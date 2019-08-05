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
	while (a->next != NULL)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

int	range_num(int max, int min)
{
	int	range;

	range = max - min + 1;
	return (range);
}