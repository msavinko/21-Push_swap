/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:27:39 by marlean           #+#    #+#             */
/*   Updated: 2022/02/18 10:49:03 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_check_repeat_sort(int *new_array, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (new_array[i] == new_array[j])
				ft_error(1);
			j++;
		}
		i++;
	}
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

void	ft_create_int_array_and_check_sort(char **array, int len)
{
	int	i;
	int	*new_array;
	int	med;

	i = 0;
	new_array = malloc(len * sizeof(int));
	while (array[i])
	{
		new_array[i] = ft_ps_atoi(array[i]);
		i++;
	}
	if (ft_check_repeat_sort(new_array, len))
	{
		med = ft_find_med(new_array, len);
		ft_push_swap(new_array, len, med);
	}
	free(new_array);
	return ;
}

void	ft_check(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		if (ft_isint(array[i]))
			i++;
		else
			ft_error(1);
	}
	ft_create_int_array_and_check_sort(array, ft_array_len(array));
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
