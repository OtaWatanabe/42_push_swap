/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:52:50 by otawatanabe       #+#    #+#             */
/*   Updated: 2024/06/25 09:49:11 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*strjoin_free(char *s1, char *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		return (NULL);
	p = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (p)
	{
		i = 0;
		while (s1[i])
		{
			p[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
		{
			p[i + j] = s2[j];
			j++;
		}
	}
	free(s1);
	return (p);
}

void	free_list(t_double_list *li)
{
	t_double_list	*ptr;
	t_double_list	*ptr_1;

	ptr = li->prev;
	while (ptr != NULL && ptr != li)
	{
		ptr_1 = ptr->prev;
		free(ptr);
		ptr = ptr_1;
	}
	if (ptr == li)
	{
		free(li);
		return ;
	}
	while (li != NULL)
	{
		ptr = li->next;
		free(li);
		li = ptr;
	}
}

void	free_info_exit(t_info *info, int if_error)
{
	free_list(info->a);
	free_list(info->b);
	free(info->operations);
	if (if_error)
		error_exit();
	exit(0);
}

void	error_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

void	free_list_exit(t_double_list *li)
{
	free_list(li);
	error_exit();
}
