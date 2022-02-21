/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:30:18 by marlean           #+#    #+#             */
/*   Updated: 2022/02/18 10:22:57 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_pslist	*ft_create_list(int *array, int len, int med)
{
	t_pslist	*stack;
	t_pslist	*current;

	len = len - 1;
	stack = NULL;
	while (len >= 0)
	{
		current = malloc(sizeof(t_pslist));
		if (!current)
			ft_error(1);
		current->value = array[len];
		current->med = med;
		current->scenario = 0;
		current->move = -1;
		current->ra = -1;
		current->rb = -1;
		current->rra = -1;
		current->rrb = -1;
		current->rr = -1;
		current->rrr = -1;
		current->next = stack;
		stack = current;
		len--;
	}
	return (stack);
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
