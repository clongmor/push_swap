/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 09:54:14 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/21 16:32:48 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

t_stack	*create_new(int value, int index)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	new->next = NULL;
	new->value = value;
	new->index = index;
	new->master = FALSE;
	return (new);
}

t_stack	*create_master(void)
{
	t_stack *master;

	if (!(master = create_new(0, 0)))
		return (NULL);
	master->master = TRUE;
	return (master);
}

void	birth_to_parent(t_stack **parent, int value, int index)
{
	t_stack *child;
	t_stack *cursor;

	if (!(child = create_new(value, index)))
		return ;
	cursor = *parent;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = child;
}

void	update_index(t_stack **stack)
{
	t_stack	*head;
	int		i;

	i = 1;
	head = *stack;
	head = head->next;
	while (head)
	{
		head->index = i;
		i++;
		head = head->next;
	}
}

void	populate_list(t_stack **stack, char **list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i])
	{
		j = ft_atoi(list[i]);
		birth_to_parent(stack, j, i);
		i++;
	}
}
