/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:32:43 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/17 10:48:35 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	len_100_toa(t_stack **a, t_stack **b)
{
	t_stack	*b_first;

	while ((*b)->next != NULL)
	{
		b_first = (*b)->next;
		if (((lstlength(b_first)) - max_index(*b)) < lstlength(b_first) / 2)
		{
			while (b_first->value != max_num(*b))
			{
				push_rrb(b);
				b_first = (*b)->next;
			}
			push_pa(b, a);
		}
		else
		{
			while (b_first->value != max_num(*b))
			{
				push_rb(b);
				b_first = (*b)->next;
			}
			push_pa(b, a);
		}
		b_first = (*b)->next;
	}
}

void	len_100_tob(t_stack **a, t_stack **b, t_stack *g_b, t_stack *g_t)
{
	t_stack	*a_first;

	a_first = (*a)->next;
	if (((lstlength(a_first)) - g_b->index) < g_t->index)
	{
		while (a_first->value != g_b->value)
		{
			push_rra(a);
			a_first = (*a)->next;
		}
		push_pb(a, b);
		a_first = (*a)->next;
	}
	else
	{
		while (a_first->value != g_t->value)
		{
			push_ra(a);
			a_first = (*a)->next;
		}
		push_pb(a, b);
		a_first = (*a)->next;
	}
}

t_stack	*group_top_check(t_stack **a, int range)
{
	t_stack	*a_first;
	t_stack	*group_top;

	a_first = (*a)->next;
	while (a_first != NULL)
	{
		group_top = NULL;
		if (a_first->value < range)
		{
			group_top = a_first;
			break ;
		}
		a_first = a_first->next;
	}
	return (group_top);
}

t_stack	*group_bot_check(t_stack *a_first, int range)
{
	t_stack	*group_bot;

	while (a_first != NULL)
	{
		if (a_first->value < range)
			group_bot = a_first;
		a_first = a_first->next;
	}
	return (group_bot);
}

void	len_100_check_num(t_stack **a, t_stack **b)
{
	int		range;
	int		range_p;
	t_stack	*group_top;
	t_stack	*group_bot;
	t_stack	*a_first;

	a_first = (*a)->next;
	range = (range_num(max_num(*a), min_num(*a)) + 1) / 5;
	range_p = range;
	while ((*a)->next != NULL)
	{
		group_top = group_top_check(a, range);
		if (group_top != NULL)
			group_bot = group_bot_check(a_first, range);
		else
		{
			range += range_p;
			a_first = (*a)->next;
			continue ;
		}
		len_100_tob(a, b, group_bot, group_top);
		a_first = (*a)->next;
	}
	len_100_toa(a, b);
}
