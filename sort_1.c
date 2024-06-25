/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:27:07 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/06/24 12:14:24 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	range_pa(t_info *info, int min, int max)
{
	int				count;
	t_double_list	*b;

	count = max - min;
	b = info->b;
	while (count && b->next != b)
	{
		check_ra_loop(info);
		if (check_pa_loop(info))
			continue ;
		if (min <= b->next->order)
		{
			pa(info);
			--count;
		}
		else
			rb(info);
	}
	check_ra_loop(info);
}

void	sort_3(t_info *info, int min)
{
	t_double_list	*a;

	a = info->a;
	if (a->next->order == min + 1 && a->prev->order == min)
		rra(info);
	else if (a->next->order == min + 1 && a->prev->order == min + 2)
		sa(info);
	else if (a->next->order == min + 2 && a->prev->order == min)
	{
		sa(info);
		rra(info);
	}
	else if (a->next->order == min + 2 && a->prev->order == min + 1)
		ra(info);
	else if (a->prev->order == min + 1)
	{
		rra(info);
		sa(info);
	}
}

void	sort_5(t_info *info)
{
	int				count;
	t_double_list	*a;
	t_double_list	*b;

	a = info->a;
	b = info->b;
	count = 0;
	while (count < 2)
	{
		if (a->next->order < 2)
		{
			pb(info);
			++count;
		}
		else
			ra(info);
	}
	sort_3(info, 2);
	if (b->next->order == 0)
		sb(info);
	pa(info);
	pa(info);
}

void	check_ra(t_info *info)
{
	t_double_list	*a;

	a = info->a;
	if (a->next->order == info->next_sort)
	{
		ra(info);
		++info->next_sort;
	}
}

int	check_pa_loop(t_info *info)
{
	t_double_list	*b;
	int				i;

	b = info->b->next;
	while (b->next != info->b && b->next->order == b->order - 1)
		b = b->next;
	if (b->order == info->next_sort)
	{
		i = info->b->next->order - info->next_sort + 1;
		while (i--)
			pa(info);
		return (1);
	}
	return (0);
}
