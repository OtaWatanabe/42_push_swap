/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:14:16 by owatanab          #+#    #+#             */
/*   Updated: 2024/06/13 11:03:35 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*t;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	s = dst;
	t = (unsigned char *)src;
	while (i < n)
	{
		s[i] = t[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char *s = NULL;
// 	char t[] = "as";
// 	printf("%s", ft_memcpy(s, t, 3));
// 	char s1[] = "sdfsd";
// 	char t1[] = "as";
// 	printf("%s", memcpy(s1, t1, 3));
// }