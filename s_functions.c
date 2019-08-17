/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:05:20 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/17 10:12:19 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack *third;

	if (((*stack)->next) && ((*stack)->next->next))
	{
		first = (*stack)->next;
		second = (*stack)->next->next;
		third = (*stack)->next->next->next;
		first->next = third;
		second->next = first;
		(*stack)->next = second;
	}
}

void	sa(t_stack **a)
{
	swap(a);
	update_index(a);
}

void	sb(t_stack **b)
{
	swap(b);
	update_index(b);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
