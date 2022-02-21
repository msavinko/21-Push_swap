/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:09:31 by marlean           #+#    #+#             */
/*   Updated: 2022/02/18 10:39:04 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(int *new_array, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (new_array[i] < new_array[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_swap_int(int *one, int *two)
{
	int	tmp;

	tmp = *one;
	*one = *two;
	*two = tmp;
}

int	ft_find_med(int *array, int len)
{
	int	med;
	int	i;
	int	*new_array;

	i = 0;
	new_array = malloc(len * sizeof(int));
	while (i < len)
	{
		new_array[i] = array[i];
		i++;
	}
	i = 0;
	while ((ft_check_sort(new_array, len)))
	{
		i = 0;
		while (i < len - 1)
		{
			if (new_array[i] > new_array[i + 1])
				ft_swap_int(&new_array[i], &new_array[i + 1]);
			i++;
		}
	}
	med = new_array[len / 2];
	free(new_array);
	return (med);
}
