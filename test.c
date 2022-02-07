#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"


void	ft_sort_hundred(t_pslist **stack_a, t_pslist **stack_b, int min, int max)
{
	t_pslist	*current_a;
	t_pslist	*current_b;

	current_a = *stack_a;
	current_b = *stack_b;
	while (current_a->next != NULL)
	{
		if (current_a->value != min || current_a->value != max || current_a->value != current_a->med)
			ft_push(stack_a, stack_b, 2);
		current_a = current_a->next;
		printf("HELLO\n");
		// ft_print_stack(stack_a, 'A');
		// ft_print_stack(stack_b, 'B');
	}
}

// int main()
// {
// 	int	array[5] = {3,4,5,1,2};

// 	ft_push_swap(array, 3, 5);

// 	return (0);
// 	//printf("MED: %d", med);
// }