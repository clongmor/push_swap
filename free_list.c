/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:20:48 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/20 13:50:51 by clongmor         ###   ########.fr       */
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
