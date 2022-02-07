/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:41:36 by marlean           #+#    #+#             */
/*   Updated: 2021/11/17 13:27:15 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	size_max;

	size_max = 18446744073709551615U;
	if (size && (count > size_max / size))
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

// void	*ft_calloc(size_t count, size_t size)
// {
// 	char	*pointer;
// 	size_t	i;
// 	size_t	quant;

// 	i = 0;
// 	quant = count * size;
// 	if (!quant)
// 		quant = 1;
// 	pointer = malloc(quant);
// 	if (!(pointer))
// 		return (NULL);
// 	while (i < quant)
// 	{
// 		pointer[i] = 0;
// 		i++;
// 	}
// 	return ((void *)pointer);
// }

// void	*ft_calloc(size_t num, size_t size)
// {
// 	void	*p;
// 	size_t	num2;

// 	if (num != 0x0 && size != 0x0)
// 	{
// 		if ((ssize_t)num < 0)
// 		{
// 			if (size != 0x1)
// 				return (NULL);
// 		}
// 		if ((ssize_t)num == -1)
// 		{
// 			if (num != 1)
// 				return (NULL);
// 		}
// 		num2 = num * size;
// 		if (num2 / size != num)
// 			return (NULL);
// 	}
// 	p = (void *)malloc(num * size);
// 	if (p == NULL)
// 		return (NULL);
// 	memset(p, 0, num * size);
// 	return (p);
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*ptr;
// 	size_t	size_max;

// 	size_max = 18446744073709551615U; //unsigned long
// 	if (size && (count > size_max / size))
// 		return (NULL);
// 	ptr = malloc(size * count);
// 	if (!ptr)
// 		return (NULL);
// 	ft_bzero(ptr, count * size);
// 	return (ptr);
// }