/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:27:39 by marlean           #+#    #+#             */
/*   Updated: 2022/02/07 15:59:28 by marlean          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char	**new_array;

	if (argc > 2)
	{
		ft_check(&argv[1]);
	}
	else if (argc == 2)
	{
		new_array = ft_split(argv[1], ' ');
		if (ft_array_len(new_array) == 1)
		{
			if (ft_isint(new_array[0]))
			{
				//free new array here;
				exit(0);
			}
			else
			{
				//free new array here
				ft_error(1);
			}
		}
		else
		{
			ft_check(&new_array[0]);
			//free new array here
		}
	}
	else
		return (0);
}

// 1 2 3 4 9 8 7 6 5
// ARG="4 7 3"; ./push_swap $ARG | ./checker_Mac $ARG
// ARG="2 1 0"; ./push_swap $ARG | wc -l