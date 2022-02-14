/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:08:14 by marlean           #+#    #+#             */
/*   Updated: 2022/02/14 17:55:44 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_line(char **line)
{
	int		result;
	int		i;
	char	*buffer;

	buffer = malloc(100000);
	if (!buffer)
		return (0);
	i = 0;
	*line = buffer;
	result = read(0, &buffer[i], 1);
	while (result > 0 && buffer[i] != '\n')
	{
		result = read(0, &buffer[i], 1);
		i++;
	}
	buffer[i] = '\0';
	return (result);
}
