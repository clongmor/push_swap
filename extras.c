/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 10:21:43 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/22 11:02:43 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	check_dup_int(t_stack **a, t_stack **b, char **check, int argv)
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
				write_error_free(a, b, check, argv);
			a_cycle = a_cycle->next;
		}
		a_first = a_first->next;
	}
	a_first = a_head;
}

char	**single_str_arg(char **argc)
{
	int		i;
	int		check;
	char	**args;

	i = 0;
	args = NULL;
	check = 0;
	while (argc[0][i] != '\0')
	{
		if (ft_isspace(argc[0][i++]) == 1)
		{
			check = 1;
			break ;
		}
	}
	if (check == 1)
		args = ft_strsplit(argc[0], ' ');
	return (args);
}

int		arg_len(char **argc, int argv)
{
	int	i;

	i = 0;
	while (argc[i])
		i++;
	if (argv == i)
		return (argv);
	return (i);
}
