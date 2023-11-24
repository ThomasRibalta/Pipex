/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:00:46 by thoribal          #+#    #+#             */
/*   Updated: 2023/11/07 09:11:06 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[i] == '\0')
		return ((char *)str);
	if (n == 0)
		return (NULL);
	while (str[i] != '\0' && i < n)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (to_find[j] == str[i + j] && i + j < n && to_find[j]
				&& str[i + j])
				j++;
			if (to_find[j] == '\0')
				return ((char *)str + i);
		}
		i++;
	}
	return (NULL);
}
