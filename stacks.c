#include "swap.h"

t_stack *create_new(int value, int index)
{
    t_stack *new;

    if (!(new = (t_stack *)malloc(sizeof(t_stack))))
        return (NULL);
    new->next = NULL;
    new->value = value;
    new->index = index;
    new->master = false;
    return (new);
}


t_stack *create_master()
{
    t_stack *master;

    if (!(master = create_new(0, 0)))
        return (NULL);

    master->master = true;

    return (master);
}


void birth_to_parent(t_stack **parent, int value, int index)
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
	int	i;

	i = 0;
	head = *stack;
	head = head->next;
	while (head)
	{
		head->index = i;
		i++;
		head = head->next;
	}
}

void push(t_stack **sender_stack, t_stack **receiver_stack)
{
    t_stack *sender;
    t_stack *receiver;

	t_stack *s_first;
    t_stack *r_first;

    sender = *sender_stack;
	receiver = *receiver_stack;

	s_first = sender->next;
	r_first = receiver->next;

    if (s_first)
	{
		sender->next = sender->next->next;
		s_first->next = r_first;
		receiver->next = s_first;
	}
}

void	pa(t_stack **b, t_stack **a)
{
	push(b, a);
	update_index(a);
	update_index(b);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	update_index(a);
	update_index(b);
}

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack *third;

	if (((*stack)->next) && ((*stack)->next->next))
	{
		first = (*stack)->next;
		second = (*stack)->next->next;
		third = (*stack)->next->next->next;
		first->next = third;
		second->next = first;
		(*stack)->next = second;
	}
}

void	sa(t_stack **a)
{
	swap(a);
	update_index(a);
}

void sb(t_stack **b)
{
	swap(b);
	update_index(b);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}

void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*first;

	head = (*stack);
	first = (*stack)->next;
	if (!(head->next) || !(head->next->next))
		return ;
	head->next = (*stack)->next->next;
	while (head->next != NULL)
	{
		head = head->next;
	}
	head->next = first;
	first->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	update_index(a);
}

void	rb(t_stack **b)
{
	rotate(b);
	update_index(b);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	head = (*stack);

	if (!(head->next) || !(head->next->next))
		return ;
	while (head->next != NULL)
	{
		head = head->next;
	}
	last = head;
	head = *stack;
	while (head->next->next != NULL)
	{
		head = head->next;
	}
	head->next = NULL;
	last->next = (*stack)->next;
	(*stack)->next = last;
}

void	rra(t_stack **a)
{
	rev_rotate(a);
	update_index(a);
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
	update_index(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	update_index(a);
	rev_rotate(b);
	update_index(b);
}

int		main(int argv, char **argc)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		int_to_char;

	i = 1;
	a = create_master();
	b = create_master();
	while (i < argv)
	{
		int_to_char = ft_atoi(argc[i]);
		birth_to_parent(&a, int_to_char, i - 1);
		i++;
	}
	while (a)
	{
		if (a->master == true)
			a = a->next;
		ft_putnbr((a)->value);
		write(1, "\n", 1);
		(a) = (a)->next;
	}
	return (0);
}

// int main()
// {
//     t_stack *a;
//     t_stack *b;

//     a = create_master();
//     b = create_master();


//     birth_to_parent(&a, 100, 0);
//     birth_to_parent(&a, 101, 1);
//     birth_to_parent(&a, 102, 2);
//     birth_to_parent(&a, 103, 3);
//     birth_to_parent(&a, -1, 4);
// 	birth_to_parent(&b, 200, 0);

// 	rotate(&b);
// 	update_index(&b);

//     return (0);
// }