/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 09:00:18 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/06/25 09:50:52 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_many(t_info *info, int size_all)
{
	max_pb(info, size_all / 2);
	b_recursive(info, 0, size_all / 2);
	max_pb_check_ra(info, size_all);
	b_recursive(info, info->next_sort, size_all);
}

void	max_pb(t_info *info, int max)
{
	int	count;

	count = 0;
	while (count < max)
	{
		if (info->a->next->order < max)
		{
			++count;
			pb(info);
		}
		else
			ra(info);
	}
}

void	max_pb_check_ra(t_info *info, int max)
{
	t_double_list	*a;

	a = info->a;
	check_ra_loop(info);
	while (a->next->order < max && a->next->order)
	{
		if (!check_pa_loop(info))
			pb(info);
		check_ra_loop(info);
	}
}

void	check_ra_loop(t_info *info)
{
	int	last_sorted;

	last_sorted = info->next_sort - 1;
	while (last_sorted < info->next_sort)
	{
		last_sorted = info->next_sort;
		check_ra(info);
	}
}
