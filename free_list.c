/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:20:48 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/20 16:17:28 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	free_lists(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*cycle;

	cycle = (*list);
	while (cycle != NULL)
	{
		tmp = cycle;
		cycle = cycle->next;
		free(tmp);
	}
	list = NULL;
}

void	write_error_free(t_stack **a, t_stack **b)
{
	free_lists(a);
	free_lists(b);
	write(1, "Error\n", 6);
	exit(0);
}

void	check_dup_int(t_stack **a, t_stack **b)
{
	t_stack	*a_head;
	t_stack	*a_first;
	t_stack	*a_cycle;

	a_first = (*a)->next;
	a_head = (*a);
	while (a_first->next != NULL)
	{
		a_cycle = a_first->next;
		while (a_cycle != NULL)
		{
			if (a_first->value == a_cycle->value)
				write_error_free(a, b);
			a_cycle = a_cycle->next;
		}
		a_first = a_first->next;
	}
	a_first = a_head;
}
