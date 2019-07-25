NAME_P = push_swap

NAME_C = checker

NAME_L = libft_o

SRCS_P = s_functions.c rr_functions.c r_functions.c p_functions.c stacks.c\
		./libft/libft.a checker_main.c error_check.c

SRCS_C = s_functions.c rr_functions.c r_functions.c p_functions.c stacks.c\
		 ./libft/libft.a checker_main.c error_check.c

FLAGS = -Wall -Wextra -Werror

MAKE = make 

HEAD_P = swap.h

all: $(NAME_P)

$(NAME_L):
	make re -C libft 

$(NAME_P): $(NAME_L) $(NAME_C)
	gcc $(SRCS_P) $(FlAGS) -o $(NAME_P)

$(NAME_C):
	gcc $(SRCS_C) $(FLAGS) -o $(NAME_C)

clean:
	# /bin/rm -f $(GHEAD)

fclean: clean
	/bin/rm -f $(NAME_P)
	/bin/rm -f $(NAME_C)

re: fclean all