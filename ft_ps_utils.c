/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 09:52:49 by marlean           #+#    #+#             */
/*   Updated: 2022/02/07 16:35:50 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ft_print_stack(t_pslist *stack, char c)
{
	int i;
	t_pslist	*current;

	i = 0;
	current = stack;
	if (!stack)
		return ;
	printf("\n----Stack %c----\n", c);
	while (stack != NULL)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}
