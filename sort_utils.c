/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:56:36 by marlean           #+#    #+#             */
/*   Updated: 2022/02/10 17:28:17 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clean_moves(t_pslist **stack)
{
	int	len;
	t_pslist	*current;

	len = ft_pslstsize(*stack);
	current = *stack;
	while (len--)
	{
		current->move = -1;
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

int	ft_count_rra(t_pslist **stack_a, int num, int size_a)
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
	return (size_a - i);
}

int	ft_min_moves(int num_one, int num_two)
{
	if (num_one == 0 && num_two == 0)
		return (num_one);
	else if (num_one < num_two)
		return (num_one);

	else
		return (num_two);
}

void	ft_count_moves(t_pslist **stack_b, int len)
{
	t_pslist	*current;
	int			one;
	int			two;

	current = *stack_b;
	while (len--)
	{
		one = current->rr + current->ra + current->rb;
		two = current->rrr + current->rra + current->rrb;
		if (one < two)
			current->move = one;
		else
			current->move = two;
		current = current->next;
	}
}

void	ft_choose_b(t_pslist **stack_a, t_pslist **stack_b)
{
	int			size_b;
	int			i;
	int			len;
	t_pslist	*current;

	i = 0;
	current = *stack_b;
	size_b = ft_pslstsize(*stack_b);
	len = size_b;
	while (len--)
	{
		current->ra = ft_count_ra(stack_a, current->value);
//		printf("RA: %d\n", current->ra);
		current->rb = i;
//		printf("RB: %d\n", current->rb);
		current->rra = ft_count_rra(stack_a,
				current->value, ft_pslstsize(*stack_a));
//		printf("RRA: %d\n", current->rra);
		if (i != 0)
			current->rrb = size_b - i;
		else
			current->rrb = i;
//		printf("RRB: %d\n", current->rrb);
		if (current->ra > 0 && current->rb > 0)
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
		else
			current->rr = 0;
//		printf("RR: %d\n", current->rr);
		if (current->rra > 0 && current->rrb > 0)
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
		else
			current->rrr = 0;
		// printf("RRR: %d\n", current->rrr);
		// printf("+++++++++++++++\n");

		current = current->next;
		i++;
	}
	ft_count_moves(stack_b, size_b);
	// current = *stack_b;
	// while (size_b--)
	// {
	// 	printf("NUMBER: %d MOVES: %d\n ra: %d, rra: %d, rb: %d, rrb: %d, rr: %d, rrr : %d\n", 
	// 		current->value, current->move, current->ra, current->rra, current->rb, current->rrb, current->rr, current->rrr);
	// 	current = current->next;
	// }
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
		else
			current = current->next;
	}
	return (min_move);
}

void	ft_move_elt(t_pslist **stack_a, t_pslist **stack_b)
{
	t_pslist	*current;
	int			size_b;
	int	i;

	current = *stack_b;
	size_b = ft_pslstsize(*stack_b);
	
	current = ft_find_min_move(stack_b, size_b - 1);
	
	// printf("NUMBER: %d MOVES: %d\n ra: %d, rra: %d, rb: %d, rrb: %d, rr: %d, rrr : %d\n", 
	// 		current->value, current->move, current->ra, current->rra, current->rb, current->rrb, current->rr, current->rrr);
		

	// printf("WE GONNA MOVE ELEMENT: %d\n", current->value);

	// 	ft_print_stack(*stack_a, 'A');
	// 	ft_print_stack(*stack_b, 'B');
	// 	printf("=====================\n");
		
//NUMBER: 414 MOVES: 1
// ra: 0, rra: 0, rb: 0, rrb: 3, rr: 1, rrr : 5

	if (current->move == 0)
		return ;
	if (current->rr < current->rrr && current->rr > 0)
	{
		i = current->rr;
		while (i--)
			ft_double(stack_a, stack_b, 1, ft_rotate);
		if (current->ra)
		{
			i = current->ra;
			while (i--)
				ft_rotate(stack_a, 1, 1);
		}
		if (current->rb)
		{
			i = current->rb;
			while (i--)
				ft_rotate(stack_b, 1, 2);
		}
		return ;
	}
	else if (current->rrr > 0)
	{
		i = current->rrr;
		while (i--)
			ft_double(stack_a, stack_b, 1, ft_rev_rotate);
		if (current->rra)
		{
			i = current->rra;
			while (i--)
				ft_rev_rotate(stack_a, 1, 1);
		}
		if (current->rrb)
		{
			i = current->rrb;
			while (i--)
				ft_rev_rotate(stack_b, 1, 2);
		}
		return ;
	}
	if (current->ra < current->rra && current->ra > 0)
	{
		i = current->ra;
		while (i--)
			ft_rotate(stack_a, 1, 1);
		return ;
	}
	else if (current->rra > 0)
	{
		i = current->rra;
		while (i--)
			ft_rev_rotate(stack_a, 1, 1);
		return ;
	}
	if (current->rb < current->rrb && current->rb > 0)
	{
		i = current->rb;
		while (i--)
			ft_rotate(stack_b, 1, 2);
		return ;
	}
	else if (current->rrb > 0)
	{
		i = current->rrb;
		while (i--)
			ft_rev_rotate(stack_b, 1, 2);
		return ;
	}

}