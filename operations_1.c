/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:52:51 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/02/18 13:40:33 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info)
{
	info->operations = ft_strjoin(info->operations, "sa\n");
	if (info->operations == NULL)
		error_exit();
	swap(info->a);
}

void	sb(t_info *info)
{
	info->operations = ft_strjoin(info->operations, "sb\n");
	if (info->operations == NULL)
		error_exit();
	swap(info->b);
}

void	ss(t_info *info)
{
	info->operations = ft_strjoin(info->operations, "ss\n");
	if (info->operations == NULL)
		error_exit();
	swap(info->a);
	swap(info->b);
}

void	pa(t_info *info)
{
	info->operations = ft_strjoin(info->operations, "pa\n");
	if (info->operations == NULL)
		error_exit();
	push(info->b, info->a);
}

void	pb(t_info *info)
{
	info->operations = ft_strjoin(info->operations, "pb\n");
	if (info->operations == NULL)
		error_exit();
	push(info->a, info->b);
}
