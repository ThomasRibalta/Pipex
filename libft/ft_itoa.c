/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:46:34 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/03 15:31:23 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenint(long nb)
{
	size_t	size;

	size = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		size = 1;
	}
	if (nb == 0)
		size = 1;
	else
	{
		while (nb)
		{
			nb = nb / 10;
			size++;
		}
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		lenint;
	int		i;
	long	nb;

	lenint = ft_lenint((long)n);
	i = 0;
	itoa = (char *)malloc((lenint + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	nb = (long)n;
	if (n < 0)
	{
		itoa[i] = '-';
		nb = -nb;
		i++;
	}
	itoa[lenint] = '\0';
	while (lenint != i)
	{
		itoa[lenint - 1] = nb % 10 + '0';
		nb /= 10;
		lenint--;
	}
	return (itoa);
}
