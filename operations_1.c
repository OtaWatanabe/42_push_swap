/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:52:51 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/01/24 20:57:29 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_double_list *a)
{
	ft_printf("sa\n");
	swap(a);
}

void 	sb(t_double_list *b)
{
	ft_printf("sb\n");
	swap(b);
}

void	ss(t_double_list *a, t_double_list *b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
}

void	pa(t_double_list *a, t_double_list *b)
{
	ft_printf("pa\n");
	push(b, a);
}

void	pb(t_double_list *a, t_double_list *b)
{
	ft_printf("pb\n");
	push(b, a);
}
