/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:56:36 by marlean           #+#    #+#             */
/*   Updated: 2022/02/14 14:38:40 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sc_one(t_pslist *current, t_pslist **stack_a, t_pslist **stack_b)
{
	int	i;

	i = current->rr;
	while (i--)
		ft_double(stack_a, stack_b, 1, ft_rotate);
	i = current->ra;
	while (i--)
		ft_rotate(stack_a, 1, 1);
	i = current->rb;
	while (i--)
		ft_rotate(stack_b, 1, 2);
	return ;
}

void	ft_sc_two(t_pslist *current, t_pslist **stack_a, t_pslist **stack_b)
{
	int	i;

	i = current->rrr;
	while (i--)
		ft_double(stack_a, stack_b, 1, ft_rev_rotate);
	i = current->rra;
	while (i--)
		ft_rev_rotate(stack_a, 1, 1);
	i = current->rrb;
	while (i--)
		ft_rev_rotate(stack_b, 1, 2);
	return ;
}

void	ft_sc_three(t_pslist *current, t_pslist **stack_a, t_pslist **stack_b)
{
	int	i;

	i = current->ra + current->rr;
	while (i--)
		ft_rotate(stack_a, 1, 1);
	i = current->rrb + current->rrr;
	while (i--)
		ft_rev_rotate(stack_b, 1, 2);
	return ;
}

void	ft_sc_four(t_pslist *current, t_pslist **stack_a, t_pslist **stack_b)
{
	int	i;

	i = current->rb + current->rr;
	while (i--)
		ft_rotate(stack_b, 1, 2);
	i = current->rra + current->rrr;
	while (i--)
		ft_rev_rotate(stack_a, 1, 1);
	return ;
}

void	ft_move_elt(t_pslist **stack_a, t_pslist **stack_b)
{
	t_pslist	*current;
	int			size_b;

	current = *stack_b;
	size_b = ft_pslstsize(*stack_b);
	current = ft_find_min_move(stack_b, size_b - 1);
	if (current->move == 0)
		return ;
	if (current->scenario == 1)
		ft_sc_one(current, stack_a, stack_b);
	else if (current->scenario == 2)
		ft_sc_two(current, stack_a, stack_b);
	else if (current->scenario == 3)
		ft_sc_three(current, stack_a, stack_b);
	else if (current->scenario == 4)
		ft_sc_four(current, stack_a, stack_b);
}
