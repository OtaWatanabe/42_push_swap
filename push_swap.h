/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 1309839457 <1309839457@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:15:17 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/01/25 13:06:01 by 1309839457       ###   ########.fr       */
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

int		ft_printf(const char *fmt, ...);
void	solve(t_double_list *input_list, int size_all);
int		same_num(t_double_list *input_list);
void	swap(t_double_list *a);
void	push(t_double_list *from, t_double_list *to);
void	rotate(t_double_list *a);
void	reverse_rotate(t_double_list *a);
void	sa(t_double_list *a);
void 	sb(t_double_list *b);
void	ss(t_double_list *a, t_double_list *b);
void	pa(t_double_list *a, t_double_list *b);
void	pb(t_double_list *a, t_double_list *b);
void	ra(t_double_list *a);
void	rb(t_double_list *b);
void	rr(t_double_list *a, t_double_list *b);
void	rra(t_double_list *a);
void	rrb(t_double_list *b);
void	rrr(t_double_list *a, t_double_list *b);
void    print_all(t_double_list *a, t_double_list *b);

#endif
