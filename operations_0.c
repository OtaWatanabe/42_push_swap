/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:39:02 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/06/21 20:47:57 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_double_list *a)
{
	t_double_list	*become_first;
	t_double_list	*become_second;
	t_double_list	*third;

	become_second = a -> next;
	become_first = become_second -> next;
	third = become_first -> next;
	if (become_first == a || become_second == a)
		return ;
	a -> next = become_first;
	become_first -> next = become_second;
	become_second -> next = third;
	third -> prev = become_second;
	become_second -> prev = become_first;
	become_first -> prev = a;
}

void	push(t_double_list *from, t_double_list *to)
{
	t_double_list	*move;
	t_double_list	*from_second;
	t_double_list	*to_first;

	move = from -> next;
	from_second = move -> next;
	to_first = to -> next;
	if (move == from)
		return ;
	to -> next = move;
	move -> next = to_first;
	from -> next = from_second;
	move -> prev = to;
	to_first -> prev = move;
	from_second -> prev = from;
}

void	rotate(t_double_list *a)
{
	t_double_list	*first;
	t_double_list	*second;
	t_double_list	*last;

	first = a -> next;
	second = first -> next;
	last = a -> prev;
	if (first == last)
		return ;
	last -> next = first;
	first -> next = a;
	a -> next = second;
	second -> prev = a;
	a -> prev = first;
	first -> prev = last;
}

void	reverse_rotate(t_double_list *a)
{
	t_double_list	*first;
	t_double_list	*last;
	t_double_list	*second_last;

	first = a -> next;
	last = a -> prev;
	second_last = last -> prev;
	if (first == last)
		return ;
	second_last -> next = a;
	a -> next = last;
	last -> next = first;
	first -> prev = last;
	last -> prev = a;
	a -> prev = second_last;
}

void	rrr(t_info *info)
{
	info->operations = strjoin_free(info->operations, "rrr\n");
	if (info->operations == NULL)
		free_info_exit(info, 1);
	reverse_rotate(info->a);
	reverse_rotate(info->b);
}
