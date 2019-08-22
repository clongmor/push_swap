/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:14:48 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/22 13:51:18 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H
# include <string.h>
# include <stdlib.h>
# include "/sgoinfre/clongmor/temp/libft/libft.h"
# include "/sgoinfre/clongmor/temp/libft/get_next_line.h"
# include <stdio.h>
# define TRUE 1
# define FALSE 0
# define PUSH_TWICE	{push_sa(stack_a); push_ra(stack_a);}
# define PUSH_TWICE_REV {push_sa(stack_a); push_rra(stack_a);}

typedef int		t_bool;

typedef struct	s_stack
{
	int				index;
	int				value;
	t_bool			master;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_stacks
{
	t_stack *a;
	t_stack *b;
}				t_stacks;

/*
** create stacks
*/
t_stack			*create_new(int value, int index);
t_stack			*create_master();
void			birth_to_parent(t_stack **parent, int value, int index);
void			populate_list(t_stack **stack, char **list);

/*
** list partitioning
*/
int				max_num(t_stack *a);
int				min_num(t_stack *a);
int				range_num(int max, int min);
int				min_index(t_stack *a);
int				max_index(t_stack *a);
int				lstlength(t_stack *lst);

/*
** update lists during ordering - checker
*/
void			push(t_stack **sender_stack, t_stack **reciver_stack);
void			pa(t_stack **b, t_stack **a);
void			pb(t_stack **a, t_stack **b);
void			swap(t_stack **stack);
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss (t_stack **a, t_stack **b);
void			rotate(t_stack **stack);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			rev_rotate(t_stack **stack);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);

/*
** update lists during ordering - push_swap
*/
void			push_pa(t_stack **b, t_stack **a);
void			push_pb(t_stack **a, t_stack **b);
void			push_ra(t_stack **a);
void			push_rb(t_stack **b);
void			push_rr(t_stack **a, t_stack **b);
void			push_rra(t_stack **a);
void			push_rrb(t_stack **b);
void			push_rrr(t_stack **a, t_stack **b);
void			push_sa(t_stack **a);
void			push_sb(t_stack **b);
void			push_ss(t_stack **a, t_stack **b);

void			exec_instr(char *buff, t_stacks \
*con, char **check, int argv);
void			check_order(t_stack **a, t_stack **b, \
char **check, int argv);
void			update_index(t_stack **stack);
int				check_sorted(t_stack *stack_a);

/*
** algos
*/
void			len_3(t_stack **stack_a);
void			len_5(t_stack **a, t_stack **b, int argv);
void			len_100_tob(t_stack **a, t_stack **b, t_stack *g_b,\
t_stack *g_t);
void			len_100_toa(t_stack **a, t_stack **b);
void			len_100_check_num(t_stack **a, t_stack **b);
t_stack			*group_top_check(t_stack **a, int range);
t_stack			*group_bot_check(t_stack *a_first, int range);
void			len_500_check_num(t_stack **a, t_stack **b);
void			len_20_check_num(t_stack **a, t_stack **b);
void			len_infinite(t_stack **a, t_stack **b);

/*
** errors
*/
int				check_input_int(int len, char **list);
int				check_dups(char **list);
int				check_maxmin(char **list);
void			error_check_suite(int argv, char **argc);
void			write_error(char **check, int argv);
void			check_dup_int(t_stack **a, t_stack **b, \
char **check, int argv);

void			free_lists(t_stack **list);
void			write_error_free(t_stack **a, t_stack **b, \
char **check, int argv);
void			free_args(char **check, int argv);
char			**single_str_arg(char **argc);
int				arg_len(char **argc, int argv);
void			free_errythang(char **check, int argv, \
t_stack **a, t_stack **b);
char			**recreate_argc(char **argc, int argv);

#endif
