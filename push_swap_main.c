/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:24:33 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/21 16:55:14 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int		check_sorted(t_stack *stack_a)
{
	stack_a = stack_a->next;
	while (stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	apply_algo(int argv, t_stack **a, t_stack **b)
{
	if (argv == 3 || argv == 4)
		len_3(a);
	else if (argv < 8 && argv > 4)
		len_5(a, b, argv);
	else if (argv > 7 && argv <= 21)
		len_20_check_num(a, b);
	else if (argv > 21 && argv <= 101)
		len_100_check_num(a, b);
	else if (argv > 101 && argv <= 501)
		len_500_check_num(a, b);
	else if (argv > 501)
		len_infinite(a, b);
}

int		main(int argv, char **argc)
{
	t_stack	*a;
	t_stack	*b;
	int		sorted;
	char	**check;

	if (argv > 1)
		argc++;
	if ((check = single_str_arg(argc)) == NULL)
		check = argc;
	error_check_suite(argv_length(check, argv), check);
	a = create_master();
	b = create_master();
	populate_list(&a, check);
	check_dup_int(&a, &b);
	if ((sorted = check_sorted(a)) == 1)
	{
		free_lists(&a);
		free_lists(&b);
		return (0);
	}
	apply_algo(argv_length(check, argv), &a, &b);
	//free_lists(&a);
	//free_lists(&b);
	free_args(check, argv_length(check, argv));
	while (1);
	return (0);
}
