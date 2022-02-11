/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:30:28 by marlean           #+#    #+#             */
/*   Updated: 2022/02/11 17:36:37 by marlean          ###   ########.fr       */
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
	int				move;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				rr;
	int				rrr;
	struct s_pslist	*next;
}					t_pslist;

//push_swap.c norminette OK!
void		ft_print_arr(int *array, int len);
void		ft_free_char(char **array);
void		ft_check_2arg(char *array);

//check.c norminette (TOO_MANY_FUNCS)
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

//list.c norminette (TOO_MANY_FUNCS)
void		ft_print_stack(t_pslist *stack, char c);
t_pslist	*ft_pslstlast(t_pslist *lst);
t_pslist	*ft_ps_one_before_lstlast(t_pslist *lst);
int			ft_pslstsize(t_pslist *lst);
void		ft_pslstadd_back(t_pslist **lst, t_pslist *new);
t_pslist	*ft_create_list(int *array, int med, int len);
int			ft_find_min(t_pslist *stack);
int			ft_find_max(t_pslist *stack);
void		ft_ps_lstclear(t_pslist **stack);
void		ft_push_swap(int *array, int med, int len);

//swap_functions.c norminette OK!
void		ft_push(t_pslist **stack_a, t_pslist **stack_b, int stack_num);
void		ft_swap(t_pslist **stack, int flag, int stack_num);
void		ft_rotate(t_pslist **stack, int flag, int stack_num);
void		ft_rev_rotate(t_pslist **stack, int flag, int stack_num);
void		ft_double(t_pslist **stack_a, t_pslist **stack_b, int flag, void (*ft_action)
				(t_pslist **stack, int flag, int stack_num));

//sort.c norminette (COMMENTS) 
void		ft_sort_three(t_pslist **stack);
void		ft_sort_five(t_pslist **stack_a, t_pslist **stack_b, int min, int max);
void		ft_sort_hundred(t_pslist **stack_a, t_pslist **stack_b, int min, int max);
int			ft_if_sorted(t_pslist **stack, int len);
int			ft_if_pre_sorted(t_pslist **stack, int len, int min, int max);
void		ft_final_sort(t_pslist **stack, int min);
//void	ft_count_movements(t_pslist **stack_a, t_pslist **stack_b);

//sort_utils.c
void		ft_clean_moves(t_pslist **stack);
void		ft_scenario_one(t_pslist **stack_a, t_pslist **stack_b);
void		ft_choose_b(t_pslist **stack_a, t_pslist **stack_b);
int			ft_count_ra(t_pslist **stack_a, int num);
int			ft_count_rra(t_pslist **stack_a, int num, int size_a);
void		ft_count_moves(t_pslist **stack_b, int len);
int			ft_min_moves(int num_one, int num_two);
t_pslist	*ft_find_min_move(t_pslist **stack, int len);
void		ft_move_elt(t_pslist **stack_a, t_pslist **stack_b);

#endif

//pip3 install push_swap_gui
//python3 -m push_swap_gui