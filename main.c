/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:33:00 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/02/17 11:33:42 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_double_list	*input_list;
	int				size;

	input_list = ft_calloc(1, sizeof(t_double_list));
	if (input_list == NULL)
		error_exit();
	size = get_input_list(input_list, argc, argv);
	if (size == 0)
		return (0);
	get_order(input_list);
	solve(input_list, size);
}
