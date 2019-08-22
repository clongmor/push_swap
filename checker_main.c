/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:22:09 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/22 11:18:15 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int		execute_instruction(char *buff, t_stack **a, t_stack **b, char **check, int argv)
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
		write_error_free(a, b, check, argv);
}

void	check_order(t_stack **a, t_stack **b, char **check, int argv)
{
	t_stack	*a_head;
	t_stack	*b_head;

	a_head = (*a);
	b_head = (*b);
	if ((b_head->next != NULL))
	{
		free_errythang(check, argv, a, b);
		write(1, "KO\n", 3);
		exit(0);
	}
	a_head = a_head->next;
	while (a_head->next != NULL)
	{
		if (!(a_head->value < a_head->next->value))
		{
			free_errythang(check, argv, a, b);
			write(1, "KO\n", 3);
			exit(0);
		}
		a_head = a_head->next;
	}
	write(1, "OK\n", 3);
}

int		main(int argv, char **argc)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	char	*line;
	char	**check;

	if (argv > 1)
		argc++;
	if ((check = single_str_arg(argc)) == NULL)
		check = argc;
	error_check_suite(arg_len(check, argv), check);
	a = create_master();
	b = create_master();
	populate_list(&a, check);
	check_dup_int(&a, &b, check, arg_len(check, argv));
	while ((i = get_next_line(0, &line)) == 1)
	{
		execute_instruction(line, &a, &b, check, arg_len(check, argv));
		free(line);
	}
	check_order(&a, &b, check, arg_len(check, argv));
	line = NULL;
	free_errythang(check, arg_len(check, argv), &a, &b);
	return (0);
}
