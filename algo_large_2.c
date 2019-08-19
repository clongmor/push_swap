/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_large_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:46:42 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/19 15:46:45 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	len_500_check_num(t_stack **a, t_stack **b)
{
	int		range;
	int		range_p;
	t_stack	*group_top;
	t_stack	*group_bot;
	t_stack	*a_first;

	a_first = (*a)->next;
	range = (range_num(max_num(*a), min_num(*a)) + 1) / 13;
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

int		lstlength(t_stack *lst)
{
	int	i;

	i = 0;
	lst = lst->next;
	if (!lst)
		return (i);
	while (!(lst == NULL))
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	len_infinite(t_stack **a, t_stack **b)
{
	int		range;
	int		range_p;
	t_stack	*group_top;
	t_stack	*group_bot;
	t_stack	*a_first;

	a_first = (*a)->next;
	range = (range_num(max_num(*a), min_num(*a)) + 1) / 17;
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
