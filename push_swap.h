/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:15:17 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/06/24 12:09:12 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf.h"

typedef struct s_double_list
{
	int						num;
	int						order;
	struct s_double_list	*next;
	struct s_double_list	*prev;
}	t_double_list;

typedef struct s_info
{
	t_double_list	*a;
	t_double_list	*b;
	char			*operations;
	int				next_sort;
}	t_info;

int		ft_printf(const char *fmt, ...);
void	solve(t_double_list *input_list, int size_all);
void	swap(t_double_list *a);
void	push(t_double_list *from, t_double_list *to);
void	rotate(t_double_list *a);
void	reverse_rotate(t_double_list *a);
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
void	pa(t_info *info);
void	pb(t_info *info);
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);
void	b_recursive(t_info *info, int b_min, int b_max);
void	range_pa(t_info *info, int min, int max);
void	sort_push_back(t_info *info, int b_size);
void	sort_3(t_info *info, int min);
void	sort_5(t_info *info);
void	check_ra(t_info *info);
void	sort_many(t_info *info, int size_all);
void	max_pb(t_info *info, int max);
void	check_ra_loop(t_info *info);
void	error_exit(void);
void	max_pb_check_ra(t_info *info, int max);
void	get_order(t_double_list *input_list);
void	reduce_and_print(char *operations);
void	reduce_push(char *operations);
int		get_input_list(t_double_list *list, int argc, char *argv[]);
void	reduce_ra(char *operations);
int		check_pa_loop(t_info *info);
void	replace_push(char *operations);
void	deal_operations(t_info *info);
void	check_excute_operations(char *rest, char *buf, t_info *info);
void	excute(t_info *info, char *str);
int		is_sorted(t_double_list *list);
void	free_list(t_double_list *li);
void	free_info_exit(t_info *info, int if_error);
void	free_list_exit(t_double_list *li);
int		split_assign(t_double_list *list, char *str);
char	*assign_num(t_double_list *list, char *str);
char	*strjoin_free(char *s1, char *s2);

#endif
