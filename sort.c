/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:33:43 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/01/24 20:52:19 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	same_num(t_double_list *input_list)
{
	t_double_list	*list;
	t_double_list	*list_compare;

	list = input_list -> next;
	while (list != input_list)
	{
		list_compare = list -> next;
		while (list_compare != input_list)
		{
			if (list_compare -> num == list -> num)
			{
				ft_printf("Error\n");
				return (1);
			}
			list_compare = list_compare -> next;
		}
		list = list -> next;
	}
	return (0);
}

void	get_order(t_double_list *input_list)
{
	t_double_list	*list;
	t_double_list	*list_compare;

	list = input_list -> next;
	while (list != input_list)
	{
		list -> order = 0;
		list_compare = input_list -> next;
		while (list_compare != input_list)
		{
			if (list_compare -> num < list -> num)
				++(list -> order);
			list_compare = list_compare -> next;
		}
		list = list -> next;
	}
}

void	move_range(t_double_list *from, t_double_list *to, int min, int max)
{
	int	move_count;

	move_count = 0;
	while (move_count < max - min)
	{
		
	}
}

void	solve(t_double_list *a, int size_all)
{
	t_double_list	*b;
	int				a_size;

	get_order(a);
	b = malloc(sizeof(t_double_list));
	if (b == NULL)
	{
		ft_printf("Error\n");
		return ;
	}
	a_size = size_all;
	while (1)
	{
		range_move()
	}
}
