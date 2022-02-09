/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:34:39 by marlean           #+#    #+#             */
/*   Updated: 2022/02/09 17:34:41 by marlean          ###   ########.fr       */
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

int	ft_if_pre_sorted(t_pslist **stack, int len, int min, int max)
{
	t_pslist	*current;

	if (!stack)
		return (0);
	current = *stack;
	while (len-- > 1)
	{
		if (current->value < current->next->value)
			current = current->next;
		else if (current->value == max && current->next->value == min)
			current = current->next;
		else
			return (0);
	}
	return (1);
}

void	ft_final_sort(t_pslist **stack, int min)
{
	if (!stack)
		return ;
	while ((*stack)->value != min)
		ft_rotate(stack, 1, 1);
}

void	ft_sort_five(t_pslist **stack_a, t_pslist **stack_b, int min, int max)
{
	while (ft_pslstsize(*stack_a) > 3)
	{
		if ((*stack_a)->value != max)
			ft_push(stack_a, stack_b, 2);
		else
			ft_rotate(stack_a, 1, 1);
	}
	if (!(ft_if_sorted(stack_a, ft_pslstsize(*stack_a))))
		ft_sort_three(stack_a);
	if ((*stack_b)->value > (*stack_b)->next->value)
		ft_swap(stack_b, 1, 2);
	while (*stack_b != NULL)
	{
		if (((*stack_b)->value < (*stack_a)->value
				&& (*stack_b)->value > ft_pslstlast(*stack_a)->value)
			|| (*stack_b)->value == min)
			ft_push(stack_b, stack_a, 1);
		else if ((*stack_b)->value > (*stack_a)->value)
			ft_rotate(stack_a, 1, 1);
		else
			ft_rev_rotate(stack_a, 1, 1);
	}
}

void	ft_sort_hundred(t_pslist **stack_a, t_pslist **stack_b,
		int min, int max)
{
	int	size_a;
	int	size_b;

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
	ft_rotate(stack_a, 1, 1);
	
	size_b = ft_pslstsize(*stack_b);

	ft_print_stack(*stack_a, 'A');
	ft_print_stack(*stack_b, 'B');
	printf("=====================\n");

	// while (size_b-- > 0)
	// {

		ft_choose_b(stack_a, stack_b);

	// }
	
	ft_print_stack(*stack_a, 'A');
	ft_print_stack(*stack_b, 'B');
	printf("=====================\n");
}
