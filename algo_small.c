/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:26:43 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/17 10:47:56 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	len_3(t_stack **stack_a)
{
	t_stack *first;
	t_stack	*second;
	t_stack	*third;

	first = (*stack_a)->next;
	second = (*stack_a)->next->next;
	third = (*stack_a)->next->next->next;
	if (second != NULL && first->value > second->value)
	{
		if (third != NULL && first->value > third->value)
		{
			if (second->value > third->value)
			{
				PUSH_TWICE_REV;
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
		PUSH_TWICE;
}

void	len_5_part(t_stack **a)
{
	t_stack	*a_first;

	a_first = (*a)->next;
	if (min_index(*a) > 3)
	{
		while (a_first->value != min_num(*a))
		{
			push_rra(a);
			a_first = (*a)->next;
		}
	}
		else while (a_first->value != min_num(*a))
		{
			push_ra(a);
			a_first = (*a)->next;
		}
}

void	len_5(t_stack **a, t_stack **b, int argv)
{
	t_stack	*a_first;
	int		i;

	i = 3;
	if (argv == 6)
		i = 2;
	if (argv == 5)
		i = 1;
	a_first = (*a)->next;
	while (i > 0)
	{
		len_5_part(a);
		push_pb(a, b);
		a_first = (*a)->next;
		i--;
	}
	len_3(a);
	push_pa(b, a);
	if (argv >= 6)
		push_pa(b, a);
	if (argv == 7)
		push_pa(b, a);
}

void	len_20_check_num(t_stack **a, t_stack **b)
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
