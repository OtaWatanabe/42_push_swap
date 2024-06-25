/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:27:33 by owatanab          #+#    #+#             */
/*   Updated: 2024/06/21 20:53:52 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;

	i = ft_strlen(s1);
	p = malloc(i + 1);
	if (p)
	{
		while (i--)
			p[i] = s1[i];
		p[ft_strlen(s1)] = 0;
	}
	return (p);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s", ft_strdup("hello"));
// }