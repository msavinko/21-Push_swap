/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:20:05 by marlean           #+#    #+#             */
/*   Updated: 2022/02/07 15:57:55 by marlean          ###   ########.fr       */
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

int	ft_ps_atoi(const char *str)
{
	unsigned int			i;
	int						sign;
	unsigned long long int	num;

	i = 0;
	num = 0;
	sign = 1;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = (-1);
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		ft_error(1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > 9223372036854775807 && sign == 1)
			return (-1);
		if (num > 9223372036854775807 && sign == -1)
			return (0);
		num = num * 10 + (str[i++] - '0');
	}
	return ((int)(num * sign));
}

int	ft_isint(char *str)
{
	long long int	num;
	int				i;

	num = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (ft_isdigit(str[i]))
		{
			num = num * 10 + (str[i++] - '0');
			if (str[i] == '-' || str[i] == '+')
				ft_error(1);
		}	
		else
			ft_error(1);
	}
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	else
		return (1);
}

void	ft_check_repeat(int *new_array, int len)
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
}

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

void ft_swap_int(int *one, int *two)
{
	int	tmp;

	tmp = *one;
	*one = *two;
	*two = tmp;
}

int	ft_find_med(int *array, int len)
{
	int med;
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
void	ft_create_int_array_and_check_sort(char **array, int len)
{
	int	i;
	int	*new_array;
	int med;

	i = 0;
	new_array = malloc(len * sizeof(int));
	while (array[i])
	{
		new_array[i] = ft_ps_atoi(array[i]);
		i++;
	}

	ft_check_repeat(new_array, len);
	if (ft_check_sort(new_array, len))
	{
		med = ft_find_med(new_array, len);
		ft_push_swap(new_array, med, len);
		free(new_array);
	}
	else
	{
		free(new_array);
		return ;
	}	
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
