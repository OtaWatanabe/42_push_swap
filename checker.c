/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:45:01 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/06/26 11:14:30 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q checker");
// }

int	main(int argc, char *argv[])
{
	t_double_list	*input_list;
	int				size;
	t_info			info;

	input_list = ft_calloc(1, sizeof(t_double_list));
	if (input_list == NULL)
		error_exit();
	size = get_input_list(input_list, argc, argv);
	if (size == 0)
	{
		free(input_list);
		return (0);
	}
	get_order(input_list);
	info.a = input_list;
	info.b = ft_calloc(1, sizeof(t_double_list));
	if (info.b == NULL)
		free_list_exit(input_list);
	info.b->next = info.b;
	info.b->prev = info.b;
	info.operations = ft_strdup("");
	if (info.operations == NULL)
		free_info_exit(&info, 1);
	deal_operations(&info);
	free_info_exit(&info, 0);
}

void	deal_operations(t_info *info)
{
	char	buf[100001];
	char	rest[7];
	int		read_num;

	read_num = 1;
	rest[0] = '\0';
	while (read_num)
	{
		read_num = read(0, buf, 100000);
		buf[read_num] = '\0';
		if (read_num == -1)
			free_info_exit(info, 1);
		check_excute_operations(rest, buf, info);
	}
	if (info->b->next != info->b)
		ft_printf("KO\n");
	else if (is_sorted(info->a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	check_excute_operations(char *rest, char *buf, t_info *info)
{
	char	*next;

	if (*buf == '\0')
		return ;
	next = ft_strchr(buf, '\n');
	if (3 < next - buf || next == NULL)
		free_info_exit(info, 1);
	ft_strlcpy(rest + ft_strlen(rest), buf, next - buf + 2);
	excute(info, rest);
	buf = next + 1;
	rest[0] = '\0';
	while (*buf)
	{
		next = ft_strchr(buf, '\n');
		if (next == NULL && ft_strlen(buf) < 3)
		{
			ft_strlcpy(rest, buf, ft_strlen(buf) + 1);
			return ;
		}
		else if (next == NULL)
			error_exit();
		else
			excute(info, buf);
		buf = next + 1;
	}
}

void	excute(t_info *info, char *str)
{
	if (ft_strncmp("sa\n", str, 3) == 0)
		sa(info);
	else if (ft_strncmp("sb\n", str, 3) == 0)
		sb(info);
	else if (ft_strncmp("ss\n", str, 3) == 0)
		ss(info);
	else if (ft_strncmp("pa\n", str, 3) == 0)
		pa(info);
	else if (ft_strncmp("pb\n", str, 3) == 0)
		pb(info);
	else if (ft_strncmp("ra\n", str, 3) == 0)
		ra(info);
	else if (ft_strncmp("rb\n", str, 3) == 0)
		rb(info);
	else if (ft_strncmp("rr\n", str, 3) == 0)
		rr(info);
	else if (ft_strncmp("rra\n", str, 4) == 0)
		rra(info);
	else if (ft_strncmp("rrb\n", str, 4) == 0)
		rrb(info);
	else if (ft_strncmp("rrr\n", str, 4) == 0)
		rrr(info);
	else
		free_info_exit(info, 1);
}
