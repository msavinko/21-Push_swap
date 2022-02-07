/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pslist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:25:56 by marlean           #+#    #+#             */
/*   Updated: 2022/02/07 15:53:48 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



t_pslist *ft_pslstlast(t_pslist *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_pslist *ft_ps_one_before_lstlast(t_pslist *lst)
{
	while (lst)
	{
		if (lst->next->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int ft_pslstsize(t_pslist *lst)
{
	int i;

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

 void ft_pslstadd_back(t_pslist **lst, t_pslist *new)
{
	t_pslist *elem;

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

t_pslist *ft_create_list(int *array, int med, int len)
{
	t_pslist *stack_a;
	t_pslist *current;
	int i;

	i = 1;
	stack_a = malloc(sizeof(t_pslist));
	if (!stack_a)
		ft_error(1);
	stack_a->value = array[0];
	stack_a->med = med;
	stack_a->next = NULL;
	current = stack_a;
	while (i < len)
	{
		current = malloc(sizeof(t_pslist));
		if (!current)
			ft_error(1);
		current->value = array[i++];
		current->med = med;
		current->next = NULL;
		ft_pslstadd_back(&stack_a, current);
	}
	return (stack_a);
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

void ft_push_swap(int *array, int med, int len)
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

	printf ("stack_len: %d\n", stack_len);
	printf("max: %d and min: %d and med: %d\n", max, min, stack_a->med);
	// ft_print_stack(stack_a, 'A');
	// ft_print_stack(stack_b, 'B');
	// printf("=======================\n");

	if (stack_len == 2)
		ft_swap(&stack_a, 1, 1);
	else if (stack_len == 3)
		ft_sort_three(&stack_a);
	else if (stack_len <= 100)
		ft_sort_hundred(&stack_a, &stack_b, min, max);

	
	// ft_print_stack(stack_a, 'A');
	// ft_print_stack(stack_b, 'B');
	// printf("=======================\n");
}