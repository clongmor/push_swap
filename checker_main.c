/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:22:09 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/17 10:43:54 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	execute_instruction(char *buff, t_stack **a, t_stack **b)
{
	if ((strcmp(buff, "sa") == 0))
		sa(a);
	else if (strcmp(buff, "sb") == 0)
		sb(b);
	else if (strcmp(buff, "ss") == 0)
		ss(a, b);
	else if (strcmp(buff, "pa") == 0)
		pa(b, a);
	else if (strcmp(buff, "pb") == 0)
		pb(a, b);
	else if (strcmp(buff, "ra") == 0)
		ra(a);
	else if (strcmp(buff, "rb") == 0)
		rb(b);
	else if (strcmp(buff, "rra") == 0)
		rra(a);
	else if (strcmp(buff, "rrb") == 0)
		rrb(b);
	else if (strcmp(buff, "rrr") == 0)
		rrr(a, b);
	else if (strcmp(buff, "rr") == 0)
		rr(a, b);
	else
	{
		write(2, "Error instruction\n", 18);
		exit(0);
	}
}

void	check_order(t_stack **a, t_stack **b)
{
	t_stack	*a_head;
	t_stack	*b_head;

	a_head = (*a);
	b_head = (*b);
	if ((b_head->next != NULL))
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	(*a) = (*a)->next;
	while ((*a)->next != NULL)
	{
		if (!((*a)->value < (*a)->next->value))
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		(*a) = (*a)->next;
	}
	write(1, "OK\n", 3);
}

int		main(int argv, char **argc)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	t_stack	*a_head;
	t_stack	*b_head;
	char	*line;

	line = error_check_suite(argv, argc);
	a = create_master();
	b = create_master();
	populate_list(&a, argc);
	//free
	while ((i = get_next_line(0, &line)) == 1)
	{
		if (strncmp(line, "q", 1) == 0)
			break ;
		execute_instruction(line, &a, &b);
		a_head = a;
		while (a != NULL)
		{
			printf("A: %d\n", a->value);
			a = a->next;
		}
		a = a_head;
		printf("\n");
		b_head = b;
		while (b != NULL)
		{
			printf("B: %d\n", b->value);
			b = b->next;
		}
		printf("\n");
		b = b_head;
	}
	check_order(&a, &b);
	return (0);
}
