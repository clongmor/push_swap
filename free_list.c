/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 13:20:48 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/22 11:01:28 by clongmor         ###   ########.fr       */
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

void	write_error_free(t_stack **a, t_stack **b, char **check, int argv)
{
	free_errythang(check, argv, a, b);
	write(1, "Error\n", 6);
	exit(0);
}

void	free_args(char **check, int argv)
{
	int i;

	i = 0;
	while (i < argv)
	{
		ft_strdel(&check[i]);
		i++;
	}
	ft_strdel(check);
	check = NULL;
}

void	free_errythang(char **check, int argv, t_stack **a, t_stack **b)
{
	free_args(check, argv);
	free_lists(a);
	free_lists(b);
}
