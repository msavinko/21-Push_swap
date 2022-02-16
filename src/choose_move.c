/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:51:19 by marlean           #+#    #+#             */
/*   Updated: 2022/02/14 14:26:49 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_count_rr(t_pslist *current)
{
	if (current->ra == current->rb)
	{
		current->rr = current->ra;
		current->ra = 0;
		current->rb = 0;
	}	
	else if (current->ra > current->rb)
	{
		current->rr = current->rb;
		current->ra = current->ra - current->rb;
		current->rb = 0;
	}	
	else
	{
		current->rr = current->ra;
		current->rb = current->rb - current->ra;
		current->ra = 0;
	}
}

void	ft_count_rrr(t_pslist *current)
{
	if (current->rra == current->rrb)
	{
		current->rrr = current->rra;
		current->rra = 0;
		current->rrb = 0;
	}	
	else if (current->rra > current->rrb)
	{
		current->rrr = current->rrb;
		current->rra = current->rra - current->rrb;
		current->rrb = 0;
	}	
	else
	{
		current->rrr = current->rra;
		current->rrb = current->rrb - current->rra;
		current->rra = 0;
	}
}

void	ft_count_double_r(t_pslist *current)
{
	if (current->ra > 0 && current->rb > 0)
		ft_count_rr(current);
	else
		current->rr = 0;
	if (current->rra > 0 && current->rrb > 0)
		ft_count_rrr(current);
	else
		current->rrr = 0;
}

void	ft_choose_b(t_pslist **stack_a, t_pslist **stack_b, int size_b)
{
	int			i;
	int			len;
	t_pslist	*current;

	i = 0;
	current = *stack_b;
	len = size_b;
	while (len--)
	{
		current->ra = ft_count_ra(stack_a, current->value);
		current->rb = i;
		current->rra = ft_pslstsize(*stack_a) - current->ra;
		if (i != 0)
			current->rrb = size_b - i;
		else
			current->rrb = i;
		ft_count_double_r(current);
		i++;
		current = current->next;
	}
	ft_count_moves(stack_b, size_b);
}

t_pslist	*ft_find_min_move(t_pslist **stack, int len)
{
	t_pslist	*min_move;
	t_pslist	*current;

	current = *stack;
	min_move = *stack;
	current = current->next;
	while (len--)
	{
		if (min_move->move > current->move)
			min_move = current;
		current = current->next;
	}
	return (min_move);
}
