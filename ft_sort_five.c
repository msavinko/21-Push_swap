#include "push_swap.h"

void	ft_sort_five(t_pslist **stack_a, t_pslist **stack_b)
{
	int	min;
	t_pslist *a;
	t_pslist *b;
	t_pslist *c;
	t_pslist *d;
	t_pslist *e;

	a = *stack_a;
	b = (*stack_a)->next;
	c = (*stack_a)->next->next;
	d = (*stack_a)->next->next->next;
	e = (*stack_a)->next->next->next->next;
	min = ft_find_min(stack_a);
	printf("min 1: %d\n", min);

	if (min == a->value)
		ft_push(stack_a, stack_b, 2);
	else if (min == b->value)
	{
		ft_swap(stack_a, 1, 1);
		ft_push(stack_a, stack_b, 2);
	}
	else if (min == c->value)
	{
		ft_rotate(stack_a, 1, 1);
		ft_rotate(stack_a, 1, 1);
		ft_push(stack_a, stack_b, 2);
	}
	else if (min == d->value)
	{
		ft_rev_rotate(stack_a, 1, 1);
		ft_rev_rotate(stack_a, 1, 1);
		ft_push(stack_a, stack_b, 2);
	}
	else if (min == e->value)
	{
		ft_rev_rotate(stack_a, 1, 1);
		ft_push(stack_a, stack_b, 2);
		printf("1\n");
	}
	printf("2\n");
	return ;
	
	min = ft_find_min(stack_a);
	printf("min 2: %d", min);
	if (min == a->value)
		ft_push(stack_a, stack_b, 2);
	else if (min == b->value)
	{
		ft_swap(stack_a, 1, 1);
		ft_push(stack_a, stack_b, 2);
	}
	else if (min == c->value)
	{
		ft_rotate(stack_a, 1, 1);
		ft_rotate(stack_a, 1, 1);
		ft_push(stack_a, stack_b, 2);
	}
	else if (min == d->value)
	{
		ft_rev_rotate(stack_a, 1, 1);
		ft_push(stack_a, stack_b, 2);
	}
	if (!(a->value < b->value && b->value < c->value))
		ft_sort_three(stack_a);
	ft_push(stack_b, stack_a, 1);
	ft_push(stack_b, stack_a, 1);
}