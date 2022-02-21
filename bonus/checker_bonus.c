/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:08:07 by marlean           #+#    #+#             */
/*   Updated: 2022/02/17 16:30:32 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_if_sorted_ch(t_pslist **stack_a, int len)
{
	t_pslist	*current;

	if (!stack_a || (len != ft_pslstsize(*stack_a)))
		return (0);
	current = *stack_a;
	while (len-- > 1)
	{
		if (current->value < current->next->value)
			current = current->next;
		else
			return (0);
	}
	return (1);
}

void	ft_do_checks(char *line, t_pslist **stack_a, t_pslist **stack_b)
{
	if (!(ft_strncmp(line, "rra", 4)))
		ft_rev_rotate(stack_a, 0, 1);
	else if (!(ft_strncmp(line, "rrb", 4)))
		ft_rev_rotate(stack_b, 0, 2);
	else if (!(ft_strncmp(line, "rrr", 4)))
		ft_double(stack_a, stack_b, 0, ft_rev_rotate);
	else if (!(ft_strncmp(line, "sa", 3)))
		ft_swap(stack_a, 0, 1);
	else if (!(ft_strncmp(line, "sb", 3)))
		ft_swap(stack_b, 0, 2);
	else if (!(ft_strncmp(line, "ss", 3)))
		ft_double(stack_a, stack_b, 0, ft_swap);
	else if (!(ft_strncmp(line, "ra", 3)))
		ft_rotate(stack_a, 0, 1);
	else if (!(ft_strncmp(line, "rb", 3)))
		ft_rotate(stack_b, 0, 2);
	else if (!(ft_strncmp(line, "rr", 3)))
		ft_double(stack_a, stack_b, 0, ft_rotate);
	else if (!(ft_strncmp(line, "pb", 3)))
		ft_push(stack_a, stack_b, 0, 2);
	else if (!(ft_strncmp(line, "pa", 3)))
		ft_push(stack_b, stack_a, 0, 1);
	else
		ft_error(1);
}

void	ft_bonus(int *array, int len)
{
	t_pslist	*stack_a;
	t_pslist	*stack_b;
	char		*line;
	int			size_a;

	line = NULL;
	stack_a = ft_create_list(array, len);
	stack_b = NULL;
	size_a = ft_pslstsize(stack_a);
	while (get_next_line(&line) > 0)
	{
		ft_do_checks(line, &stack_a, &stack_b);
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	if (ft_if_sorted_ch(&stack_a, size_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_ps_lstclear(&stack_a);
	exit(0);
}

int	main(int argc, char **argv)
{
	if (argc > 2)
		ft_check_ch(&argv[1]);
	else if (argc == 2)
		ft_check_2arg_ch(argv[1]);
	else
		return (0);
}
