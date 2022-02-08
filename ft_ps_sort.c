/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:34:39 by marlean           #+#    #+#             */
/*   Updated: 2022/02/08 17:18:26 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_pslist **stack)
{
	t_pslist	*a;
	t_pslist	*b;
	t_pslist	*c;

	if (!stack)
		return ;
	a = *stack;
	b = (*stack)->next;
	c = (*stack)->next->next;
	if (c->value > a->value && c->value > b->value)
		ft_swap(stack, 1, 1);
	else if (a->value > b->value && a->value > c->value)
	{
		ft_rotate(stack, 1, 1);
		if (b->value > c->value)
			ft_swap(stack, 1, 1);
	}
	else if (b->value > a->value && b->value > c->value)
	{
		ft_rev_rotate(stack, 1, 1);
		if (c->value > a->value)
			ft_swap(stack, 1, 1);
	}
}

int	ft_if_sorted(t_pslist **stack, int len)
{
	t_pslist	*current;

	if (!stack)
		return (0);
	current = *stack;
	while (len-- > 1)
	{
		if (current->value < current->next->value)
			current = current->next;
		else
			return (0);
	}
	return (1);
}
// int	ft_pre_sorted(t_pslist *stack, int size)
// {
// 	t_pslist	*current;

// 	current = stack;
// 	while (size-- > 0)
// 	{

// 	}
// 	return 
// }
// void	ft_count_movements(t_pslist **stack_a, t_pslist **stack_b)
// {
// 	(*stack_a)->ra = 0;
// 	(*stack_b)->rb = 0;

// 	//printf("RA: %d", (*stack_a)->ra);
// }

// void	ft_choose_b(t_pslist **stack_a, t_pslist **stack_b)
// {
// 	ft_count_movements(stack_a, stack_b);
// }

void	ft_sort_hundred(t_pslist **stack_a, t_pslist **stack_b,
		int min, int max)
{
	int	size_a;

	size_a = ft_pslstsize(*stack_a);
	while (size_a-- > 0)
	{
		if ((*stack_a)->value == min || (*stack_a)->value == max
			|| (*stack_a)->value == (*stack_a)->med)
			ft_rotate(stack_a, 1, 1);
		else
		{
			ft_push(stack_a, stack_b, 2);
			if ((*stack_b)->value > (*stack_b)->med)
				ft_rotate(stack_b, 1, 2);
		}
	}
	if (!(ft_if_sorted(stack_a, ft_pslstsize(*stack_a))))
		ft_sort_three(stack_a);
	//size_b = ft_pslstsize(*stack_b);
	// ft_pre_sorted(stack_a, ft_pslstsize(*stack_a));
	// ft_sorted(stack_a, ft_pslstsize(*stack_a));
	// size_b = ft_pslstsize(*stack_b);
	// while (size_b-- > 0)
	// {
	// 	ft_push(stack_b, stack_a, 1);
	// }
	//size of stack_a and stack_b;
	//create function check_sort_stack;
	//create function pre_sort_stack;
	// ft_sort_three(stack_b);
	ft_print_stack(*stack_a, 'A');
	ft_print_stack(*stack_b, 'B');
	printf("=======================\n");
}
