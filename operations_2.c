/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:59:20 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/06/21 20:49:09 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *info)
{
	info->operations = strjoin_free(info->operations, "ra\n");
	if (info->operations == NULL)
		free_info_exit(info, 1);
	rotate(info->a);
}

void	rb(t_info *info)
{
	info->operations = strjoin_free(info->operations, "rb\n");
	if (info->operations == NULL)
		free_info_exit(info, 1);
	rotate(info->b);
}

void	rr(t_info *info)
{
	info->operations = strjoin_free(info->operations, "rr\n");
	if (info->operations == NULL)
		free_info_exit(info, 1);
	rotate(info->a);
	rotate(info->b);
}

void	rra(t_info *info)
{
	info->operations = strjoin_free(info->operations, "rra\n");
	if (info->operations == NULL)
		free_info_exit(info, 1);
	reverse_rotate(info->a);
}

void	rrb(t_info *info)
{
	info->operations = strjoin_free(info->operations, "rrb\n");
	if (info->operations == NULL)
		free_info_exit(info, 1);
	reverse_rotate(info->b);
}
