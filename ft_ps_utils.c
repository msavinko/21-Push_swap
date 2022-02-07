/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 09:52:49 by marlean           #+#    #+#             */
/*   Updated: 2022/02/02 10:23:11 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int error_code)
{
	write(2, "Error\n", 6);
	exit(error_code);
}

int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	while(array[i])
		i++;
	return(i);
}

int	ft_create_int_array_and_check_sort(char **array, int len)
{
	int		i;
	int		new_array[len];

	i = 0;
	while (array[i])
	{
		new_array[i] = ft_atoi(array[i]);
		i++;
	}
	i = 0;
	while (i < len - 1)
	{
		if (new_array[i] < new_array[i+1])
			i++;
		else
			return (1);
	}
	return (0);
}