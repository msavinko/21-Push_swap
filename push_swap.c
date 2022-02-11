/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:27:39 by marlean           #+#    #+#             */
/*   Updated: 2022/02/11 15:56:52 by marlean          ###   ########.fr       */
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

//=======================

void	ft_free_char(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	i--;
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

void	ft_check_2arg(char *array)
{
	char	**new_array;

	new_array = ft_split(array, ' ');
	if (ft_array_len(new_array) == 1)
	{
		if (ft_isint(new_array[0]))
		{
			ft_free_char(new_array);
			exit(0);
		}
		else
		{
			ft_free_char(new_array);
			ft_error(1);
		}
	}
	else
	{
		ft_check(&new_array[0]);
		ft_free_char(new_array);
	}
}

int	main(int argc, char **argv)
{
	if (argc > 2)
		ft_check(&argv[1]);
	else if (argc == 2)
		ft_check_2arg(argv[1]);
	else
		return (0);
}

// 1 2 3 4 9 8 7 6 5
// ARG="4 7 3"; ./push_swap $ARG | ./checker_Mac $ARG
// ARG="2 1 0"; ./push_swap $ARG | wc -l