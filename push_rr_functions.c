/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rr_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:04:37 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/17 10:05:04 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	push_rra(t_stack **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
	update_index(a);
}

void	push_rrb(t_stack **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
	update_index(b);
}

void	push_rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	update_index(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
	update_index(b);
}
