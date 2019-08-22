/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:22:09 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/22 13:51:13 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void		exec_instr(char *buff, t_stacks *con, char **check, int argv)
{
	if ((strcmp(buff, "sa") == 0))
		sa(&con->a);
	else if (strcmp(buff, "sb") == 0)
		sb(&con->b);
	else if (strcmp(buff, "ss") == 0)
		ss(&con->a, &con->b);
	else if (strcmp(buff, "pa") == 0)
		pa(&con->b, &con->a);
	else if (strcmp(buff, "pb") == 0)
		pb(&con->a, &con->b);
	else if (strcmp(buff, "ra") == 0)
		ra(&con->a);
	else if (strcmp(buff, "rb") == 0)
		rb(&con->b);
	else if (strcmp(buff, "rra") == 0)
		rra(&con->a);
	else if (strcmp(buff, "rrb") == 0)
		rrb(&con->b);
	else if (strcmp(buff, "rrr") == 0)
		rrr(&con->a, &con->b);
	else if (strcmp(buff, "rr") == 0)
		rr(&con->a, &con->b);
	else
		write_error_free(&(con->a), &(con->b), check, argv);
}

void		check_order(t_stack **a, t_stack **b, char **check, int argv)
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

t_stacks	*get_stacks(void)
{
	t_stacks *con;

	if (!(con = malloc(sizeof(t_stacks))))
		return (NULL);
	con->a = create_master();
	con->b = create_master();
	return (con);
}

int			main(int argv, char **argc)
{
	int			i;
	t_stacks	*con;
	char		*line;
	char		**check;

	if (argv > 1)
		argc++;
	if ((check = single_str_arg(argc)) == NULL)
		check = recreate_argc(argc, argv);
	error_check_suite(arg_len(check, argv), check);
	con = get_stacks();
	populate_list(&(con->a), check);
	check_dup_int(&(con->a), &(con->b), check, arg_len(check, argv));
	while ((i = get_next_line(0, &line)) == 1)
	{
		exec_instr(line, con, check, arg_len(check, argv));
		free(line);
	}
	check_order(&(con->a), &(con->b), check, arg_len(check, argv));
	line = NULL;
	free_errythang(check, arg_len(check, argv), &(con->a), &(con->b));
	return (0);
}
