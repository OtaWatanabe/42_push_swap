/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:34:00 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/02/18 13:54:49 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reduce_and_print(char *operations)
{
	reduce_push(operations);
	reduce_ra(operations);
	replace_push(operations);
	write(1, operations, ft_strlen(operations));
}

void	reduce_push(char *operations)
{
	char	*prev;
	char	*start;

	start = operations;
	prev = start;
	while (*operations)
	{
		if ((!ft_strncmp(operations, "pb", 2) && !ft_strncmp(prev, "pa", 2))
			|| (!ft_strncmp(operations, "pa", 2) && !ft_strncmp(prev, "pb", 2)))
		{
			ft_memmove(prev, operations + 3, ft_strlen(operations) - 2);
			if (prev != start)
				prev -= 3;
		}
		else
			prev = operations;
		operations = ft_strchr(prev, '\n') + 1;
	}
}

void	reduce_ra(char *operations)
{
	char	*prev;
	char	*start;

	start = operations;
	prev = start;
	while (*operations)
	{
		if ((!ft_strncmp(operations, "rb", 2) && !ft_strncmp(prev, "ra", 2))
			|| (!ft_strncmp(operations, "ra", 2) && !ft_strncmp(prev, "rb", 2)))
		{
			ft_memcpy(prev, "rr", 2);
			ft_memmove(operations, operations + 3, ft_strlen(operations) - 2);
			if (prev != start && (prev - 3 == start || *(prev - 4) == '\n'))
				prev -= 3;
		}
		else
		{
			prev = operations;
			operations = ft_strchr(prev, '\n') + 1;
		}
	}
}

void	replace_push(char *operations)
{
	char	*second;
	char	*first;

	first = operations;
	second = ft_strchr(first, '\n');
	if (second == NULL)
		return ;
	operations = ft_strchr(++second, '\n');
	if (operations == NULL)
		return ;
	++operations;
	while (*operations)
	{
		if (!ft_strncmp(first, "pb", 2) && !ft_strncmp(second, "ra", 2)
			&& !ft_strncmp(operations, "pa", 2))
		{
			ft_memcpy(first, "sa", 2);
			ft_memmove(operations, operations + 3, ft_strlen(operations) - 2);
			continue ;
		}
		first = second;
		second = operations;
		operations = ft_strchr(operations, '\n') + 1;
	}
}
