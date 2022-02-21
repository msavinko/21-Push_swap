/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:36:41 by marlean           #+#    #+#             */
/*   Updated: 2022/02/18 09:46:31 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clean_moves(t_pslist **stack)
{
	int			len;
	t_pslist	*current;

	len = ft_pslstsize(*stack);
	current = *stack;
	while (len--)
	{
		current->move = -1;
		current->scenario = 0;
		current->ra = -1;
		current->rb = -1;
		current->rra = -1;
		current->rrb = -1;
		current->rr = -1;
		current->rrr = -1;
		current = current->next;
	}
}

int	ft_count_ra(t_pslist **stack_a, int num)
{
	int			i;
	t_pslist	*current;

	i = 0;
	current = *stack_a;
	if (num > ft_pslstlast(current)->value && num < current->value)
		return (i);
	else
	{
		while (num < current->value)
		{
			i++;
			current = current->next;
		}
		while (num > current->value)
		{
			i++;
			current = current->next;
		}
	}
	return (i);
}

void	ft_count_scenarios(t_pslist *current, int moves, int scenario)
{
	current->move = moves;
	current->scenario = scenario;
}

void	ft_count_moves(t_pslist **stack_b, int len)
{
	t_pslist	*current;
	int			one;
	int			two;
	int			three;
	int			four;

	current = *stack_b;
	while (len--)
	{
		one = current->rr + current->ra + current->rb;
		two = current->rrr + current->rra + current->rrb;
		three = current->rr + current->ra + current->rrr + current->rrb;
		four = current->rr + current->rb + current->rrr + current->rra;
		if (one <= two && one <= three && one <= four)
			ft_count_scenarios(current, one, 1);
		else if (two <= one && two <= three && two <= four)
			ft_count_scenarios(current, two, 2);
		else if (three <= one && three <= two && three <= four)
			ft_count_scenarios(current, three, 3);
		else
			ft_count_scenarios(current, four, 4);
		current = current->next;
	}
}
