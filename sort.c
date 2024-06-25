/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:33:43 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/06/25 09:48:31 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_order(t_double_list *input_list)
{
	t_double_list	*list;
	t_double_list	*list_compare;

	list = input_list->next;
	while (list != input_list)
	{
		list->order = 0;
		list_compare = input_list->next;
		while (list_compare != input_list)
		{
			if (list_compare->num < list->num)
				++(list->order);
			else if (list_compare != list && list_compare->num == list->num)
				free_list_exit(list);
			list_compare = list_compare->next;
		}
		list = list->next;
	}
}

void	solve(t_double_list *a, int size_all)
{
	t_double_list	*b;
	t_info			info;

	b = ft_calloc(1, sizeof(t_double_list));
	if (b == NULL)
		free_list_exit(a);
	b->next = b;
	b->prev = b;
	info.a = a;
	info.b = b;
	info.next_sort = 0;
	info.operations = ft_strdup("");
	if (size_all == 0)
		return ;
	else if (size_all == 3)
		sort_3(&info, 0);
	else if (size_all == 5)
		sort_5(&info);
	else
		sort_many(&info, size_all);
	if (info.operations == NULL)
		free_info_exit(&info, 1);
	reduce_and_print(info.operations);
	free_info_exit(&info, 0);
}

void	b_recursive(t_info *info, int b_min, int b_max)
{
	int	mid;

	if (b_max - b_min <= 3)
	{
		sort_push_back(info, b_max - b_min);
		return ;
	}
	mid = (b_min + b_max) / 2;
	range_pa(info, mid, b_max);
	b_min = info->next_sort;
	b_recursive(info, b_min, mid);
	max_pb_check_ra(info, b_max);
	b_min = info->next_sort;
	b_recursive(info, b_min, b_max);
}

void	sort_push_back(t_info *info, int b_size)
{
	t_double_list	*b;

	b = info->b;
	if (b_size <= 0)
		return ;
	if (b_size == 3 && b->next->order < b->next->next->order
		&& b->prev->order < b->next->order)
		sb(info);
	pa(info);
	check_ra_loop(info);
	sort_push_back(info, b_size - 1);
}

int	is_sorted(t_double_list *list)
{
	t_double_list	*tmp;

	tmp = list->next;
	while (tmp->next != list)
	{
		if (tmp->order + 1 != tmp->next->order)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
