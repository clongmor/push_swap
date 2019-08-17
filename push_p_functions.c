/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_p_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:32:25 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/17 10:32:28 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	push_pa(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pa\n", 3);
	update_index(a);
	update_index(b);
}

void	push_pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
	update_index(a);
	update_index(b);
}
