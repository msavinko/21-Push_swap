/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlean <marlean@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:51:31 by marlean           #+#    #+#             */
/*   Updated: 2022/02/15 19:02:57 by marlean          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHECKER_H
# define CHECKER_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483647

typedef struct s_pslist
{
	int				value;
	int				move;
	int				scenario;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				rr;
	int				rrr;
	struct s_pslist	*next;
}					t_pslist;

t_pslist	*ft_pslstlast(t_pslist *lst);
t_pslist	*ft_ps_one_before_lstlast(t_pslist *lst);
int			ft_pslstsize(t_pslist *lst);
t_pslist	*ft_create_list(int *array, int len);
void		ft_ps_lstclear(t_pslist **stack);
int			ft_isint(char *str);
int			ft_ps_atoi(const char *str);
int			ft_array_len(char **array);
void		ft_free_char(char **array);
void		ft_error(int error_code);
void		ft_bonus(int *array, int len);
void		ft_do_checks(char *line, t_pslist **stack_a, t_pslist **stack_b);
int			ft_if_sorted_ch(t_pslist **stack_a, int len);

void		ft_check_2arg_ch(char *array);
void		ft_check_repeat_ch(int *new_array, int len);
void		ft_create_int_array_and_check_sort_ch(char **array, int len);
void		ft_check_ch(char **array);


void		ft_push(t_pslist **stack_a, t_pslist **stack_b, int flag, int stack_num);
void		ft_swap(t_pslist **stack, int flag, int stack_num);
void		ft_rotate(t_pslist **stack, int flag, int stack_num);
void		ft_rev_rotate(t_pslist **stack, int flag, int stack_num);
void		ft_double(t_pslist **stack_a, t_pslist **stack_b, int flag,
				void (*ft_action)(t_pslist **stack, int flag, int stack_num));


#endif