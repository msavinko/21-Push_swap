/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:27:39 by marlean           #+#    #+#             */
/*   Updated: 2022/02/04 18:11:54 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_arr(int *array, int len)
{
	int	i;

	i = 0;
	printf("array: ");
	while (i < len)
	{
		printf(" %d ", array[i]);
		i++;
	}
	printf("\n");
}

int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	char	**new_array;

	if (argc > 2)
	{
		if (ft_check(&argv[1]))
			ft_push_swap(&argv[1]);
	}
	else if (argc == 2)
	{
		new_array = ft_split(argv[1], ' ');
		if (ft_array_len(new_array) == 1)
		{
			if (ft_isint(new_array[0]))
				exit(0);
			else
				ft_error(1);
		}
		else
		{
			if (ft_check(&new_array[0]))
				ft_push_swap(&new_array[0]);
		}
	}
	else
		return (0);
}

// 1 2 3 4 9 8 7 6 5
// ARG="4 7 3"; ./push_swap $ARG | ./checker_Mac $ARG
// ARG="2 1 0"; ./push_swap $ARG | wc -l