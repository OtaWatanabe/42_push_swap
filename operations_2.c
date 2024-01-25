/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 1309839457 <1309839457@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:59:20 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/01/25 12:51:05 by 1309839457       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_double_list *a)
{
	ft_printf("ra\n");
	rotate(a);
}

void	rb(t_double_list *b)
{
	ft_printf("rb\n");
	rotate(b);
}

void	rr(t_double_list *a, t_double_list *b)
{
	ft_printf("rr\n");
	rotate(a);
	rotate(b);
}

void	rra(t_double_list *a)
{
	ft_printf("rra\n");
	reverse_rotate(a);
}

void	rrb(t_double_list *b)
{
	ft_printf("rra\n");
	reverse_rotate(b);
}
