/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:37:34 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/17 10:37:36 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	push(t_stack **sender_stack, t_stack **receiver_stack)
{
	t_stack *sender;
	t_stack *receiver;
	t_stack *s_first;
	t_stack *r_first;

	sender = *sender_stack;
	receiver = *receiver_stack;
	s_first = sender->next;
	r_first = receiver->next;
	if (s_first)
	{
		sender->next = sender->next->next;
		s_first->next = r_first;
		receiver->next = s_first;
	}
}

void	pa(t_stack **b, t_stack **a)
{
	push(b, a);
	update_index(a);
	update_index(b);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	update_index(a);
	update_index(b);
}
