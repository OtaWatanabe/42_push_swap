/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 1309839457 <1309839457@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:40:44 by 1309839457        #+#    #+#             */
/*   Updated: 2024/01/25 13:05:08 by 1309839457       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_all(t_double_list *a, t_double_list *b)
{
    t_double_list   *get;

    ft_printf("a\n");
    get = a->next;
    while (get != a)
	{
		ft_printf("num:%d\torder:%d\n", get->num, get->order);
		get = get->next;
	}
    get = b->next;
    ft_printf("b\n");
    while (get != b)
	{
		ft_printf("num:%d\torder:%d\n", get->num, get->order);
		get = get->next;
	}
}
