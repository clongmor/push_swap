#include "swap.h"

int		check_input_int(int len, char **list)
{
	int	i;
	int	j;

	i = 1;
	while (i < (len))
	{
		if (!(list[i][0]))
			return (0);
		j = 0;
		while (list[i][j])
		{
			if (ft_isdigit(list[i][j]) == false)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_dups(char **list)
{
	int		i;
	int		j;

	i = 1;
	while (list[i])
	{
		j = i + 1;
		while (list[j])
		{
			if (ft_strcmp(list[i], list[j]) == 0) 
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	populate_list(t_stack **stack, char **list)
{
	int	i;
	int	j;

	i = 1;
	while (list[i])
	{
		j = ft_atoi(list[i]);
		birth_to_parent(stack, j, i);
		i++;
	}
}

int		check_maxmin(char **list)
{
	int		i;
	int		len;
	char	*min;
	char	*max;

	i = 1;
	min = ft_itoa(MIN_INT);
	max = ft_itoa(MAX_INT);
	while (list[i])
	{
		len = ft_strlen(list[i]);
		if (len > 10 && (strcmp(list[i], min) > 0))
			return (0);
		else if (len == 10 && (strcmp(list[i], max) > 0))
			return (0);
		i++;
	}
	return (1);
}

void		execute_instruction(char *buff, t_stack **a, t_stack **b)
{
	if ((strcmp(buff, "sa\n") == 0))
		sa(a);
	else if (strcmp(buff, "sb\n") == 0)
		sb(b);
	else if (strcmp(buff, "ss\n") == 0)
		ss(a, b);
	else if (strcmp(buff, "pa\n") == 0)
		pa(b, a);
	else if (strcmp(buff, "pb\n") == 0)
		pb(a, b);
	else if (strcmp(buff, "ra\n") == 0)
		ra(a);
	else if (strcmp(buff, "rb\n") == 0)
		rb(b);
	else if (strcmp(buff, "rra\n") == 0)
		rra(a);
	else if (strcmp(buff, "rrb\n") == 0)
		rrb(b);
	else if (strcmp(buff, "rrr\n") == 0)
		rrr(a, b);
	else if (strcmp(buff, "rr\n") == 0)
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

char	**error_check_suite(int argv, char **argc)
{
	int		i;
	char	**line;

	if (!(line = malloc(sizeof(char**) * 1)))
		exit(0);
	if (argv == 1)
	{
		printf("the programme quit.");
		exit(0);
	}
	else if ((i = check_input_int(argv, argc)) == 0)
	{
		write(2, "Error int\n", 10);
		exit(0);
	}
	else if ((i = check_dups(argc)) == 0)
	{
		write(2, "Error dup\n", 10);
		exit(0);
	}
	else if ((i = check_maxmin(argc)) == 0)
	{
		write(2, "Error max\n", 10);
		exit(0);
	}
	return (line);
}

int		main(int argv, char **argc)
{
	int 	i;
	t_stack	*a;
	t_stack	*b;
	t_stack	*a_head;
	t_stack	*b_head;
	char	**line;
	char	buff[5];

	line = error_check_suite(argv, argc);
	a = create_master();
	b = create_master();
	populate_list(&a, argc);
	//while ((i = get_next_line(0, line)) == 1);
	while ((i = read(0, buff, 4)) > 0)
	{
		if (strncmp(buff, "q", 1) == 0)
			break ;
		execute_instruction(buff, &a, &b);
		a_head = a;
		while (a != NULL)
		{
			printf("list a has: %d\n", a->value);
			a = a->next;
		}
		a = a_head;
		printf("\n");
		b_head = b;
		while (b != NULL)
		{
			printf("list b has: %d\n", b->value);
			b = b->next;
		}
		b = b_head;
	}
	check_order(&a, &b);
	//receive a list of instructions from stdin/pushswap with gnl
	return (0);
}