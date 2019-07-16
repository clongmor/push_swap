#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;

typedef struct s_stack 
{
    int             index;
    int             value;
    bool            master;
    struct s_stack  *next;
}               t_stack;



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
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
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

void	a(t_stack **stack)
{
	swap(stack);
}

void b(t_stack **stack)
{
	swap(stack);
}

int main()
{
    t_stack *a;
    t_stack *b;

    a = create_master();
    b = create_master();


    birth_to_parent(&a, 100, 0);
    birth_to_parent(&a, 101, 1);
    birth_to_parent(&a, 102, 2);
    birth_to_parent(&a, 103, 3);
    birth_to_parent(&a, -1, 4);
	birth_to_parent(&b, 200, 0);

	swap(&a);
	update_index(&a);

    return (0);
}