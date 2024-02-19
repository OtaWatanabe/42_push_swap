/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:45:01 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/02/19 12:18:11 by otawatanabe      ###   ########.fr       */
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
	deal_operations(input_list);
}

void	deal_operations(t_double_list *a)
{
	char	buf[100001];
	char	rest[5];
	int		read_num;

	read_num = 100000;
	rest[0] = '\0';
	while (read_num == 100000)
	{
		read_num = read(0, buf, 100000);
		buf[read_num] = '\0';
		if (read_num == -1)
			error_exit();
		check_excute_operations(rest, buf);
	}
}

void	*check_excute_operations(char *rest, char *buf)
{
	char	*next;

	if (*buf == '\0')
		return ;
	next = ft_strchr(buf, '\n');
	if (3 < next - buf || next == NULL)
		error_exit();
	ft_memcpy(rest + ft_strlen(rest), buf, next - buf + 1);
	buf = next + 1;
	while (*buf)
	{
		
	}
}