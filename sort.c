/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:33:43 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/02/20 08:45:55 by otawatanabe      ###   ########.fr       */
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
				error_exit();
			list_compare = list_compare->next;
		}
		list = list->next;
	}
}

void	solve(t_double_list *a, int size_all)
{
	t_double_list	*b;
	t_info			*info;

	if (is_sorted(a))
		return ;
	info = ft_calloc(1, sizeof(t_info));
	b = malloc(sizeof(t_double_list));
	if (b == NULL || info == NULL)
		error_exit();
	b->next = b;
	b->prev = b;
	info->a = a;
	info->b = b;
	info->operations = "";
	if (size_all == 0)
		return ;
	else if (size_all == 3)
		sort_3(info, 0);
	else if (size_all == 5)
		sort_5(info);
	else
		sort_many(info, size_all);
	reduce_and_print(info->operations);
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
