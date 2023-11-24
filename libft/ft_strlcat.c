/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:16:11 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/05 11:08:14 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lendest;

	i = 0;
	j = 0;
	lendest = ft_strlen(dst);
	if (!dst || !src)
		return (i);
	while (dst[i])
		i++;
	while (src[j] && (j + i + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (size > j)
		dst[i + j] = '\0';
	if (size <= lendest)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + lendest);
}
