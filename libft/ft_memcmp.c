/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:08:24 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/05 12:13:05 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s3;
	unsigned char	*s4;
	size_t			i;

	i = 0;
	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	if (n <= 0 || !s1 || !s2)
		return (0);
	while (i < n)
	{
		if (s3[i] != s4[i])
			return (s3[i] - s4[i]);
		i++;
	}
	if (i < n)
		return (0 - s4[i]);
	return (0);
}
