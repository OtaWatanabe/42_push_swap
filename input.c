/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:13:05 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/06/25 09:49:43 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_overflow(int integer_now, int sign, int next_digit)
{
	if (sign == 1 && INT_MAX < (long)integer_now * 10 + next_digit)
		return (1);
	if (sign == -1 && (long)integer_now * 10 + next_digit * -1 < INT_MIN)
		return (1);
	return (0);
}

char	*assign_num(t_double_list *list, char *str)
{
	int				sign;
	t_double_list	*new;

	sign = 1;
	new = ft_calloc(1, sizeof(t_double_list));
	list->next = new;
	if (str == NULL || new == NULL)
		free_list_exit(list);
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	if (*str == '\0' || *str == ' ')
		free_list_exit(list);
	new->prev = list;
	while (*str && *str != ' ')
	{
		if (*str < '0' || '9' < *str
			|| check_overflow(new->num, sign, *str - '0'))
			free_list_exit(list);
		new->num = 10 * new->num + sign * (*str++ - '0');
	}
	return (str);
}

int	split_assign(t_double_list *list, char *str)
{
	int	num_count;

	num_count = 0;
	while (1)
	{
		while (*str == ' ')
			++str;
		if (*str == '\0')
			break ;
		if (++num_count < 0)
			free_list_exit(list);
		str = assign_num(list, str);
		list = list->next;
	}
	if (num_count == 0)
		free_list_exit(list);
	return (num_count);
}

int	get_input_list(t_double_list *list, int argc, char *argv[])
{
	int				i;
	int				size;
	int				num_count;
	t_double_list	*first;

	i = 1;
	first = list;
	size = 0;
	while (i < argc)
	{
		num_count = split_assign(list, argv[i]);
		size += num_count;
		while (num_count--)
			list = list->next;
		++i;
		if (size < 0)
			free_list_exit(list);
	}
	list->next = first;
	first->prev = list;
	return (size);
}
