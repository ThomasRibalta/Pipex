/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:56:34 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/03 15:13:26 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoine(char const *s1, char const *s2)
{
	char	*s3;
	int		i;

	i = 0;
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)])
	{
		s3[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	s3[i] = '\0';
	return (s3);
}
