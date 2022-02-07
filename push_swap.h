/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:30:28 by marlean           #+#    #+#             */
/*   Updated: 2022/02/07 15:58:51 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483647

typedef struct s_pslist
{
	int				value;
	int				med;
	struct s_pslist	*next;
}					t_pslist;

int			ft_array_len(char **array);

void		ft_error(int error_code);
int			ft_array_len(char **array);
int			ft_ps_atoi(const char *str);
int			ft_isint(char *str);
void		ft_check_repeat(int *new_array, int len);
int			ft_check_sort(int *new_array, int len);
void		ft_swap_int(int *one, int *two);
int			ft_find_med(int *array, int len);
void		ft_create_int_array_and_check_sort(char **array, int len);
void		ft_check(char **array);

void		ft_push_swap(int *array, int med, int len);
t_pslist	*ft_create_list(int *array, int med, int len);
void		ft_pslstadd_back(t_pslist **lst, t_pslist *new);
int			ft_pslstsize(t_pslist *lst);

void		ft_push(t_pslist **stack_a, t_pslist **stack_b, int stack_num);
void		ft_swap(t_pslist **stack, int flag, int stack_num);
void		ft_rotate(t_pslist **stack, int flag, int stack_num);
void		ft_rev_rotate(t_pslist **stack, int flag, int stack_num);
void		ft_double(t_pslist **stack_a, t_pslist **stack_b, void (*ft_action)
				(t_pslist **stack, int flag, int stack_num));

t_pslist	*ft_pslstlast(t_pslist *lst);
t_pslist	*ft_ps_one_before_lstlast(t_pslist *lst);

void	ft_sort_three(t_pslist **stack);
void	ft_sort_hundred(t_pslist **stack_a, t_pslist **stack_b, int min, int max);

void	ft_sort_five(t_pslist **stack_a, t_pslist **stack_b);
int		ft_find_min(t_pslist *stack);
int		ft_find_max(t_pslist *stack);

void	ft_print_stack(t_pslist *stack, char c);
void		ft_print_arr(int *array, int len);


#endif