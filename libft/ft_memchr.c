/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:23:26 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/05 12:14:20 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	size_t			i;

	s1 = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		if (s1[i] == (unsigned char)c)
			return ((void *)(s1 + i));
		i++;
	}
	return (NULL);
}
