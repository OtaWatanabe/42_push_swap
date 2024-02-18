/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:59:20 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/02/18 13:34:08 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *info)
{
	info->operations = ft_strjoin(info->operations, "ra\n");
	if (info->operations == NULL)
		error_exit();
	rotate(info->a);
}

void	rb(t_info *info)
{
	info->operations = ft_strjoin(info->operations, "rb\n");
	if (info->operations == NULL)
		error_exit();
	rotate(info->b);
}

void	rr(t_info *info)
{
	info->operations = ft_strjoin(info->operations, "rr\n");
	if (info->operations == NULL)
		error_exit();
	rotate(info->a);
	rotate(info->b);
}

void	rra(t_info *info)
{
	info->operations = ft_strjoin(info->operations, "rra\n");
	if (info->operations == NULL)
		error_exit();
	reverse_rotate(info->a);
}

void	rrb(t_info *info)
{
	info->operations = ft_strjoin(info->operations, "rrb\n");
	if (info->operations == NULL)
		error_exit();
	reverse_rotate(info->b);
}
