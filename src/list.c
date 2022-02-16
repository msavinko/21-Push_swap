/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:25:56 by marlean           #+#    #+#             */
/*   Updated: 2022/02/14 13:32:09 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min(t_pslist *stack)
{
	int	min;

	if (!(stack))
		return (0);
	min = INT_MAX;
	while (stack)
	{
		if ((stack)->value < min)
			min = (stack)->value;
		(stack) = (stack)->next;
	}
	return (min);
}

int	ft_find_max(t_pslist *stack)
{
	int	max;

	if (!(stack))
		return (0);
	max = INT_MIN;
	while (stack)
	{
		if ((stack)->value > max)
			max = (stack)->value;
		(stack) = (stack)->next;
	}
	return (max);
}

void	ft_push_swap(int *array, int len)
{
	int			min;
	int			max;
	int			stack_len;
	t_pslist	*stack_a;
	t_pslist	*stack_b;

	stack_a = ft_create_list(array, len);
	stack_b = NULL;
	max = ft_find_max(stack_a);
	min = ft_find_min(stack_a);
	stack_len = ft_pslstsize(stack_a);
	if (stack_len == 2)
		ft_swap(&stack_a, 1, 1);
	else if (stack_len == 3)
		ft_sort_three(&stack_a);
	else
		ft_sort_five(&stack_a, &stack_b, min, max);
	if (ft_if_pre_sorted(&stack_a, ft_pslstsize(stack_a), min, max))
		ft_final_sort(&stack_a, min);
	ft_ps_lstclear(&stack_a);
	exit(0);
}
