/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:30:28 by marlean           #+#    #+#             */
/*   Updated: 2022/02/18 10:08:24 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_pslist
{
	int				value;
	int				move;
	int				med;
	int				scenario;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				rr;
	int				rrr;
	struct s_pslist	*next;
}					t_pslist;

void		ft_swap_int(int *one, int *two);
int			ft_find_med(int *array, int len);
void		ft_free_char(char **array);
void		ft_check_2arg(char *array);
int			ft_array_len(char **array);
int			ft_ps_atoi(const char *str);
int			ft_isint(char *str);
void		ft_error(int error_code);
int			ft_check_repeat_sort(int *new_array, int len);
void		ft_create_int_array_and_check_sort(char **array, int len);
void		ft_check(char **array);
t_pslist	*ft_pslstlast(t_pslist *lst);
t_pslist	*ft_ps_one_before_lstlast(t_pslist *lst);
int			ft_pslstsize(t_pslist *lst);
t_pslist	*ft_create_list(int *array, int len, int med);
void		ft_ps_lstclear(t_pslist **stack);
int			ft_find_min(t_pslist *stack);
int			ft_find_max(t_pslist *stack);
void		ft_push_swap(int *array, int len, int med);
void		ft_push(t_pslist **stack_a, t_pslist **stack_b, int flag,
				int stack_num);
void		ft_swap(t_pslist **stack, int flag, int stack_num);
void		ft_rotate(t_pslist **stack, int flag, int stack_num);
void		ft_rev_rotate(t_pslist **stack, int flag, int stack_num);
void		ft_double(t_pslist **stack_a, t_pslist **stack_b, int flag,
				void (*ft_action)(t_pslist **stack, int flag, int stack_num));
void		ft_sort_three(t_pslist **stack);
int			ft_if_sorted(t_pslist **stack, int len);
int			ft_if_pre_sorted(t_pslist **stack, int len, int min, int max);
void		ft_final_sort(t_pslist **stack, int min);
void		ft_sort_all(t_pslist **stack_a, t_pslist **stack_b,
				int min, int max);
void		ft_clean_moves(t_pslist **stack);
int			ft_count_ra(t_pslist **stack_a, int num);
void		ft_count_moves(t_pslist **stack_b, int len);
void		ft_count_scenarios(t_pslist *current, int moves, int scenario);
void		ft_count_rr(t_pslist *current);
void		ft_count_rrr(t_pslist *current);
void		ft_count_double_r(t_pslist *current);
void		ft_choose_b(t_pslist **stack_a, t_pslist **stack_b, int size_b);
t_pslist	*ft_find_min_move(t_pslist **stack, int len);
void		ft_sc_one(t_pslist *current, t_pslist **stack_a,
				t_pslist **stack_b);
void		ft_sc_two(t_pslist *current, t_pslist **stack_a,
				t_pslist **stack_b);
void		ft_sc_thre(t_pslist *current, t_pslist **stack_a,
				t_pslist **stack_b);
void		ft_sc_four(t_pslist *current, t_pslist **stack_a,
				t_pslist **stack_b);
void		ft_move_elt(t_pslist **stack_a, t_pslist **stack_b);
void		ft_bonus(int *array, int len);
void		ft_do_checks(char *line, t_pslist **stack_a, t_pslist **stack_b);
int			ft_if_sorted_ch(t_pslist **stack_a, int len);

#endif