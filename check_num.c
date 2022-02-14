/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:28:12 by marlean           #+#    #+#             */
/*   Updated: 2022/02/14 17:57:11 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int error_code)
{
	write(2, "Error\n", 6);
	exit(error_code);
}

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

int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
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
	if (ft_strlen(str) > 12)
		ft_error(1);
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
