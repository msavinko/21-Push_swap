/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:34:39 by marlean           #+#    #+#             */
/*   Updated: 2022/02/07 16:55:22 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_three(t_pslist **stack)
{
	t_pslist *a;
	t_pslist *b;
	t_pslist *c;

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

void	ft_sort_hundred(t_pslist **stack_a, t_pslist **stack_b, int min, int max)
{
	int size = ft_pslstsize(*stack_a);
	while (size-- > 0)
	{
		//printf("MED: %d, MIN %d, MAX %d\n", (*stack_a)->med, min, max);
		if ((*stack_a)->value == min || (*stack_a)->value == max || (*stack_a)->value == (*stack_a)->med)
			ft_rotate(stack_a, 1, 1);
		else
			ft_push(stack_a, stack_b, 2); //if less than MED then push and rotate.
		//(*stack_a) = (*stack_a)->next;
	}
	//size of stack_a and stack_b;
	//create function check_sort_stack;
	//create function pre_sort_stack;
	ft_sort_three(stack_a);
	ft_sort_three(stack_b);
		ft_print_stack(*stack_b, 'B');
		ft_print_stack(*stack_a, 'A');
		// ft_print_stack(*stack_a, 'A');
}