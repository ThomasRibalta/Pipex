/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:30:12 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/02 11:30:16 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src, size_t n)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (dest[nb])
		nb++;
	while (src[i] && i < n)
	{
		dest[nb] = src[i];
		i++;
		nb++;
	}
	dest[nb] = '\0';
	return (dest);
}
