/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pslist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:25:56 by marlean           #+#    #+#             */
/*   Updated: 2022/02/04 13:09:10 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_stack(t_pslist *stack, char c)
{
	int i;

	i = 0;
	printf("\n----Stack %c----\n", c);
	while (stack != NULL)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
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

t_pslist *ft_create_list(char **array)
{
	t_pslist *stack_a;
	t_pslist *current;
	int i;

	i = 1;
	stack_a = malloc(sizeof(t_pslist));
	if (!stack_a)
		ft_error(1);
	stack_a->value = ft_atoi(array[0]);
	stack_a->next = NULL;
	current = stack_a;
	while (array[i])
	{
		current = malloc(sizeof(t_pslist));
		if (!current)
			ft_error(1);
		current->value = ft_atoi(array[i++]);
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



void ft_push_swap(char **array)
{
	int			min;
	int			max;
	int			stack_len;
	t_pslist	*stack_a;
	t_pslist	*stack_b;

	stack_a = ft_create_list(array);
	stack_b = NULL;
	max = ft_find_max(stack_a);
	min = ft_find_min(stack_a);
	stack_len = ft_pslstsize(stack_a);

	if (stack_len == 2)
		ft_swap(&stack_a, 1, 1);
	else if (stack_len == 3)
		ft_sort_three(&stack_a);

	printf("max: %d and min: %d\n", max, min);

	ft_print_stack(stack_a, 'A');
	ft_print_stack(stack_b, 'B');
	printf("=======================\n");

	
	//ft_sort_five(&stack_a, &stack_b);
	
	// ft_print_stack(stack_a, 'A');
	// ft_print_stack(stack_b, 'B');
	// printf("=======================\n");
}