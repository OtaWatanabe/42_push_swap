/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 1309839457 <1309839457@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:33:43 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/01/25 13:14:18 by 1309839457       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	same_num(t_double_list *input_list)
{
	t_double_list	*list;
	t_double_list	*list_compare;

	list = input_list->next;
	while (list != input_list)
	{
		list_compare = list->next;
		while (list_compare != input_list)
		{
			if (list_compare->num == list->num)
			{
				ft_printf("Error\n");
				return (1);
			}
			list_compare = list_compare->next;
		}
		list = list->next;
	}
	return (0);
}

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
			list_compare = list_compare->next;
		}
		list = list->next;
	}
}

void	range_move(t_double_list *a, t_double_list *b, int min, int max, int a_to_b)
{
	int	c;

	c = 0;
	while (c < max - min)
	{
		if (min <= a->next->num && b->next->num <= max)
		{
			if (a_to_b)
				pb(a, b);
			else
				pa(a, b);
			++c;
		}
		else if (a_to_b)
			ra(a);
		else
			rb(b);
	}
}

void	solve(t_double_list *a, int size_all)
{
	t_double_list	*b;
	// int				a_size;

	get_order(a);
	b = malloc(sizeof(t_double_list));
	if (b == NULL)
	{
		ft_printf("Error\n");
		return ;
	}
	b -> next = b;
	b -> prev = b;
	if (size_all == 0)
		return ;

	pb(a, b);
	print_all(a, b);
	pb(a, b);
	print_all(a, b);
	sa(a);
	print_all(a, b);
	ss(a, b);
	print_all(a, b);
	sb(b);
	print_all(a, b);
	ra(a);
	print_all(a, b);
	rb(b);
	print_all(a, b);
	rr(a, b);
	print_all(a, b);
	rra(a);
	print_all(a, b);
	rrb(b);
	print_all(a, b);
	rrr(a, b);
	print_all(a, b);
	pb(a, b);
	print_all(a, b);
	
	// a_size = size_all;
	// while (1)
	// {
	// 	range_move(a, b, 0, size_all / 2, 1);
	// }
}
