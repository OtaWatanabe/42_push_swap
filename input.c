/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:13:05 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/02/18 13:43:06 by otawatanabe      ###   ########.fr       */
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

void	error_exit(void)
{
	ft_printf("Error\n");
	exit(0);
}

char	*assign_input(t_double_list *list, char *str)
{
	int				sign;
	t_double_list	*new;

	sign = 1;
	new = ft_calloc(1, sizeof(t_double_list));
	list->next = new;
	if (str == NULL || *str == '\0' || *str == ' ' || new == NULL)
		error_exit();
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	if (*str == '\0' || *str == ' ')
		error_exit();
	new->prev = list;
	while (*str && *str != ' ')
	{
		if (*str < '0' || '9' < *str
			|| check_overflow(new->num, sign, *str - '0'))
			error_exit();
		new->num = 10 * new->num + sign * (*str++ - '0');
	}
	return (str);
}

int	get_input_list(t_double_list *list, int argc, char *argv[])
{
	int				i;
	t_double_list	*first;
	char			*next_str;
	int				size;

	i = 1;
	first = list;
	size = 0;
	next_str = argv[1];
	while (i < argc)
	{
		next_str = assign_input(list, ft_strtrim(next_str, " "));
		list = list->next;
		if (*next_str == '\0')
		{
			++i;
			if (i < argc)
				next_str = argv[i];
		}
		++size;
	}
	list->next = first;
	first->prev = list;
	return (size);
}
