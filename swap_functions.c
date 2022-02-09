/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:55:21 by marlean           #+#    #+#             */
/*   Updated: 2022/02/09 15:58:44 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_pslist **stack_a, t_pslist **stack_b, int stack_num)
{
	t_pslist	*one_a;
	t_pslist	*one_b;

	if (!(*stack_a))
		return ;
	one_a = *stack_a;
	one_b = *stack_b;
	*stack_a = (*stack_a)->next;
	one_a->next = one_b;
	*stack_b = one_a;
	if (stack_num == 1)
		write(1, "pa\n", 3);
	else if (stack_num == 2)
		write(1, "pb\n", 3);
}

void	ft_swap(t_pslist **stack, int flag, int stack_num)
{
	t_pslist	*one;
	t_pslist	*two;
	t_pslist	*three;

	if (!(*stack) || ft_pslstsize(*stack) < 2)
		return ;
	one = *stack;
	two = (*stack)->next;
	three = (*stack)->next->next;
	*stack = (*stack)->next;
	two->next = one;
	one->next = three;
	if (flag != 0)
	{
		if (stack_num == 1)
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
}

void	ft_rotate(t_pslist **stack, int flag, int stack_num)
{
	t_pslist	*first;
	t_pslist	*last;

	if (!(*stack) || ft_pslstsize(*stack) < 2)
		return ;
	first = *stack;
	last = ft_pslstlast(*stack);
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
	if (flag != 0)
	{
		if (stack_num == 1)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
}

void	ft_rev_rotate(t_pslist **stack, int flag, int stack_num)
{
	t_pslist	*one;
	t_pslist	*two;
	t_pslist	*three;

	if (!(*stack) || ft_pslstsize(*stack) < 2)
		return ;
	one = *stack;
	two = ft_ps_one_before_lstlast(*stack);
	three = ft_pslstlast(*stack);
	*stack = three;
	three->next = one;
	two->next = NULL;
	if (flag != 0)
	{
		if (stack_num == 1)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
}

void	ft_double(t_pslist **stack_a, t_pslist **stack_b, int flag,
	void (*ft_action)(t_pslist **stack, int flag, int stack_num))
{
	int	print_flag;

	print_flag = 0;
	if (!(*stack_a) || !(*stack_b) || ft_pslstsize(*stack_a) < 2
		|| ft_pslstsize(*stack_b) < 2)
		return ;
	ft_action(stack_a, print_flag, 1);
	ft_action(stack_b, print_flag, 2);
	if (flag != 0)
	{
		if (ft_action == ft_swap)
			write(1, "ss\n", 3);
		else if (ft_action == ft_rotate)
			write(1, "rr\n", 3);
		else if (ft_action == ft_rev_rotate)
			write(1, "rrr\n", 4);
	}
}
