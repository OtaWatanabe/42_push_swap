/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 1309839457 <1309839457@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:13:05 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/01/25 13:05:48 by 1309839457       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear(t_double_list *list)
{
	t_double_list	*next;
	// ft_printf("clear\n");
	while (list)
	{
		next = list -> next;
		free(list);
		list = next;
	}
}

int	check_overflow(int integer_now, int sign, int next_digit)
{
	// ft_printf("check_overflow\n");
	if (sign == 1 && INT_MAX < (long long)integer_now * 10 + next_digit)
		return (1);
	if (sign == -1 && (long long)integer_now * 10 + next_digit * -1 < INT_MIN)
		return (1);
	return (0);
}

int	assign_input(t_double_list *list, char *str)
{
	int	sign;

	sign = 1;
	// ft_printf("assign_input\n");
	list -> num = 0;
	list -> next = NULL;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || '9' < *str
			|| check_overflow(list -> num, sign, *str - '0'))
			return (0);
		list -> num = 10 * (list -> num) + sign * (*str - '0');
		++str;
	}
	return (1);
}

int	get_input_list(t_double_list *list, int argc, char *argv[])
{
	int				i;
	t_double_list	*first;

	i = 1;
	// ft_printf("get_input_list\n");
	first = list;
	while (i < argc)
	{
		list -> next = malloc(sizeof(t_double_list));
		if (list -> next == NULL ||
		assign_input(list -> next, *(argv + i - 1)) == 0)
		{
			clear (first);
			ft_printf("Error\n");
			return (0);
		}
		list -> next -> prev = list;
		list = list -> next;
		++i;
	}
	list -> next = first;
	first -> prev = list;
	return (1);
}

int	main(int argc, char *argv[])
{
	t_double_list	*input_list;

	input_list = malloc(sizeof(t_double_list));
	if (input_list == NULL)
		return (0);
	if (get_input_list(input_list, argc, argv + 1) == 0)
		return (0);
	if (same_num(input_list))
		return (0);
	solve(input_list, argc - 1);
}
