/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:59:36 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/05 12:50:18 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*c;

	if (size != 0 && nmemb > (-1 / size))
		return (NULL);
	c = malloc(nmemb * size);
	if (!c)
		return (NULL);
	ft_bzero(c, nmemb * size);
	return (c);
}
