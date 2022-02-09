/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:25:56 by marlean           #+#    #+#             */
/*   Updated: 2022/02/09 14:43:52 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_pslist *stack, char c)
{
	int			i;
	t_pslist	*current;

	i = 0;
	current = stack;
	if (!stack)
		return ;
	printf("\n----Stack %c----\n", c);
	while (stack != NULL)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

t_pslist	*ft_pslstlast(t_pslist *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_pslist	*ft_ps_one_before_lstlast(t_pslist *lst)
{
	while (lst)
	{
		if (lst->next->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	ft_pslstsize(t_pslist *lst)
{
	int	i;

	i = 0;
	if (lst)
	{
		while (lst)
		{
			i++;
			lst = lst->next;
		}
	}
	return (i);
}

void	ft_pslstadd_back(t_pslist **lst, t_pslist *new)
{
	t_pslist	*elem;

	elem = *lst;
	if (elem)
	{
		while (elem->next)
			elem = elem->next;
		elem->next = new;
	}
	else
		*lst = new;
}

t_pslist	*ft_create_list(int *array, int med, int len)
{
	t_pslist	*stack;
	t_pslist	*current;
	int			i;

	i = len - 1;
	stack = NULL;
	while (i >= 0)
	{
		current = malloc(sizeof(t_pslist));
		if (!current)
			ft_error(1);
		current->value = array[i];
		current->med = med;
		current->move = 0;
		current->ra = 0;
		current->rb = 0;
		current->rra = 0;
		current->rrb = 0;
		current->rr = 0;
		current->rrr = 0;
		current->next = stack;
		stack = current;
		i--;
	}
	return (stack);
}

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

void	ft_ps_lstclear(t_pslist **stack)
{
	t_pslist	*next_el;

	if (!stack)
		return ;
	while (*stack)
	{
		next_el = (*stack)->next;
		free(*stack);
		*stack = next_el;
	}
}

void	ft_push_swap(int *array, int med, int len)
{
	int			min;
	int			max;
	int			stack_len;
	t_pslist	*stack_a;
	t_pslist	*stack_b;

	stack_a = ft_create_list(array, med, len);
	stack_b = NULL;
	max = ft_find_max(stack_a);
	min = ft_find_min(stack_a);
	stack_len = ft_pslstsize(stack_a);
	if (stack_len == 2)
		ft_swap(&stack_a, 1, 1);
	else if (stack_len == 3)
		ft_sort_three(&stack_a);
	else if (stack_len <= 5)
		ft_sort_five(&stack_a, &stack_b, min, max);
	else if (stack_len <= 100)
		ft_sort_hundred(&stack_a, &stack_b, min, max);
	if (ft_if_pre_sorted(&stack_a, ft_pslstsize(stack_a), min, max))
		ft_final_sort(&stack_a, min);
	ft_ps_lstclear(&stack_a);
	exit(0);
}
