/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:20:05 by marlean           #+#    #+#             */
/*   Updated: 2022/02/04 18:59:07 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int error_code)
{
	write(2, "Error\n", 6);
	exit(error_code);
}

static int	ft_isspace(char c)
{
	if ((c == ' ' || c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r'))
		return (1);
	else
		return (0);
}

int	ft_ps_atoi(const char *str)
{
	unsigned int			i;
	int						sign;
	unsigned long long int	num;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
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
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_error(1);
		if (ft_isdigit(str[i]))
			num = num * 10 + (str[i++] - '0');
		else
			return (0);
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

int	ft_create_int_array_and_check_sort(char **array, int len)
{
	int	i;
	int	*new_array;

	i = 0;
	new_array = malloc(len * sizeof(int));
	while (array[i])
	{
		new_array[i] = ft_ps_atoi(array[i]);
		i++;
	}
	ft_check_repeat(new_array, len);
	i = 0;
	while (i < len - 1)
	{
		if (new_array[i] < new_array[i + 1])
			i++;
		else
		{
			free(new_array);
			return (1);
		}
	}
	free(new_array);
	return (0);
}

int	ft_check(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
	{
		if (ft_isint(array[i]))
			i++;
		else
			ft_error(1);
	}
	if (ft_create_int_array_and_check_sort(array, ft_array_len(array)))
		return (1);
	return (0);
}
