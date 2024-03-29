NAME_P = push_swap

NAME_C = checker

NAME_L = libft_o

SRCS_P = s_functions.c rr_functions.c r_functions.c p_functions.c stacks.c\
		./libft/libft.a error_check.c list_partition.c algo_small.c\
		push_swap_main.c push_p_functions.c push_r_functions.c push_rr_functions.c\
		push_s_functions.c algo_large_1.c algo_large_2.c free_list.c extras.c \
		argc_malloc.c

SRCS_C = s_functions.c rr_functions.c r_functions.c p_functions.c stacks.c\
		 ./libft/libft.a checker_main.c error_check.c free_list.c extras.c \
		 argc_malloc.c

FLAGS = -Wall -Wextra -Werror

MAKE = make 

HEAD_P = swap.h

all: $(NAME_P)

$(NAME_L):
	make re -C libft 

$(NAME_P): $(NAME_C)
	gcc $(SRCS_P) $(FlAGS) -o $(NAME_P)

$(NAME_C):
	gcc $(SRCS_C) $(FLAGS) -o $(NAME_C)

clean:
	make clean -C libft

fclean: 
	/bin/rm -f $(NAME_P)
	/bin/rm -f $(NAME_C)

re: fclean all
