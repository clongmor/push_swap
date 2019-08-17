/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_r_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:23:56 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/17 10:24:19 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	push_ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
	update_index(a);
}

void	push_rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
	update_index(b);
}

void	push_rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
