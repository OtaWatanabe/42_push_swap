/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:52:51 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/06/21 20:48:45 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info)
{
	info->operations = strjoin_free(info->operations, "sa\n");
	if (info->operations == NULL)
		free_info_exit(info, 1);
	swap(info->a);
}

void	sb(t_info *info)
{
	info->operations = strjoin_free(info->operations, "sb\n");
	if (info->operations == NULL)
		free_info_exit(info, 1);
	swap(info->b);
}

void	ss(t_info *info)
{
	info->operations = strjoin_free(info->operations, "ss\n");
	if (info->operations == NULL)
		free_info_exit(info, 1);
	swap(info->a);
	swap(info->b);
}

void	pa(t_info *info)
{
	info->operations = strjoin_free(info->operations, "pa\n");
	if (info->operations == NULL)
		free_info_exit(info, 1);
	push(info->b, info->a);
}

void	pb(t_info *info)
{
	info->operations = strjoin_free(info->operations, "pb\n");
	if (info->operations == NULL)
		free_info_exit(info, 1);
	push(info->a, info->b);
}
