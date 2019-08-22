/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clongmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 11:51:17 by clongmor          #+#    #+#             */
/*   Updated: 2019/08/22 12:21:42 by clongmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

char	**recreate_argc(char **argc, int argv)
{
	int		i;
	char	**check;
	int		len;

	i = 0;
	check = (char**)malloc(sizeof(char*) * argv);
	while (i < (argv - 1))
	{
		len = ft_strlen(argc[i]);
		check[i] = (char*)malloc(len * sizeof(char) + 1);
		ft_strcpy(check[i], argc[i]);
		i++;
	}
	check[argv - 1] = NULL;
	return (check);
}
