#include "swap.h"

int		check_input_int(int len, char **list)
{
	int	i;
	int	j;

	j = 0;
	i = len - 1;
	while (i < (len - 1))
	{
		while (list[i][j] != '\0')
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
		birth_to_parent(stack, j, i - 1);
		i++;
	}
}

int		check_maxmin(char **list)
{
	int	i;
	int	j;

	i = 1;
	while (list[i])
	{
		j = ft_atoi(list[i]);
		if ((j > MAX_INT) || (j < MIN_INT))
			return (0);
		i++;
	}
	return (1);
}

int		main(int argv, char **argc)
{
	int 	i;
	t_stack	*a;
	t_stack	*b;

	if (argv == 1)
		exit(0);
	else if ((i = check_input_int(argv, argc)) == 0)
	{
		write(3, "Error int\n", 10);
		exit(0);
	}
	else if ((i = check_dups(argc)) == 0)
	{
		write(3, "Error dup\n", 10);
		exit(0);
	}
	else if ((i = check_maxmin(argc)) == 0)
	{
		write(3, "Error max\n", 10);
		exit(0);
	}
	a = create_master();
	b = create_master();
	populate_list(a, argc);

	//receive a list of instructions from stdin/pushswap
	//check instructions are formatted correctly
	//check instructions are valid and assosc. with a function
	
	//read and apply the commands if all input it valid.
	//write result KO/OK to output with \n


	//call error function to stderror


	
}