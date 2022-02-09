/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:56:36 by marlean           #+#    #+#             */
/*   Updated: 2022/02/09 18:10:46 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_scenario_one(t_pslist **stack_a, t_pslist **stack_b)
// {
	
// }

void	ft_choose_b(t_pslist **stack_a, t_pslist **stack_b)
{
	int			size_a;
	int			size_b;
	int			i;
	int			len;
	t_pslist	*current;
	
	i = 0;
	current = *stack_b;
	size_a = ft_pslstsize(*stack_a);
	size_b = ft_pslstsize(*stack_b);
	len = size_b;
	while(len--)
	{
	//	current->ra = ft_count_ra(stack_a, current->value);
		current->rb = i;
//		current->rra = 
		if (i != 0)
			current->rrb = size_b - i;
		else
			current->rrb = i;
		current = current->next;
		i++;
	}
	current = *stack_b;
	while (size_b--)
	{
		printf("stack_b ra: %d\n", current->ra);
		printf("stack_b rra: %d\n", current->rra);
		printf("stack_b rb: %d\n", current->rb);
		printf("stack_b rrb: %d\n", current->rrb);
		printf("=====================\n");
		current = current->next;
	}
	// size_b = ft_pslstsize(*stack_b);
	// if ((*stack_b)->move == 0)
	// {
	// 	ft_push(stack_b, stack_a, 1);
	// 	return ;
	// }


	// ft_scenario_one(stack_a, stack_b);
	// ft_scenario_two(stack_a, stack_b);
	// ft_scenario_three(stack_a, stack_b);
	// ft_scenario_four(stack_a, stack_b);
}
