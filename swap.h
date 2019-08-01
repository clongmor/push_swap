#ifndef SWAP_H
# define SWAP_H
# include <string.h>
# include <stdlib.h>
# include "/sgoinfre/clongmor/temp/libft/libft.h"
# include "/sgoinfre/clongmor/temp/libft/get_next_line.h"
# include <stdio.h>
# define true 1
# define false 0
# define MAX_INT 2147483647
# define MIN_INT -2147483648 

typedef int bool;

typedef struct s_stack 
{
    int             index;
    int             value;
    bool            master;
    struct s_stack  *next;
}               t_stack;

//create stacks
t_stack		*create_new(int value, int index);
t_stack		*create_master();
void		birth_to_parent(t_stack **parent, int value, int index);
void		populate_list(t_stack **stack, char **list);

//update lists during ordering
void		push(t_stack **sender_stack, t_stack **reciver_stack);
void		pa(t_stack **b, t_stack **a);
void		pb(t_stack **a, t_stack **b);
void		swap(t_stack **stack);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss (t_stack **a, t_stack **b);
void		rotate(t_stack **stack);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rev_rotate(t_stack **stack);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

void        execute_instruction(char *buff, t_stack **a, t_stack **b);
void        check_order(t_stack **a, t_stack **b);
void		update_index(t_stack **stack);

//errors
int			check_input_int(int len, char **list);
int			check_dups(char **list);
int			check_maxmin(char **list);
char        *error_check_suite(int argv, char **argc);

#endif