/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:19:51 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/17 10:42:43 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (list[i][j] == '-' && ft_isdigit(list[i][j + 1]) == TRUE)
				j++;
			if (ft_isdigit(list[i][j]) == FALSE)
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

void	write_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

char	*error_check_suite(int argv, char **argc)
{
	int		i;
	char	*line;

	if (!(line = malloc(sizeof(char*) * 1)))
		exit(0);
	if (argv == 1)
		exit(0);
	else if ((i = check_input_int(argv, argc)) == 0)
		write_error();
	else if ((i = check_dups(argc)) == 0)
		write_error();
	else if ((i = check_maxmin(argc)) == 0)
		write_error();
	return (line);
}
