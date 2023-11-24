/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:50:45 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/06 12:59:02 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

size_t	get_start(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (is_set(set, s1[i]) && s1[i])
		i++;
	return (i);
}

size_t	get_end(const char *s1, const char *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (is_set(set, s1[i - 1]) && s1[i - 1])
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	int		i;

	start = get_start(s1, set);
	end = get_end(s1, set);
	i = 0;
	if (start >= end)
		return (ft_calloc(1, 1));
	trim = malloc((end - start + 1) * sizeof(char));
	if (!trim)
		return (NULL);
	while (start + i < end)
	{
		trim[i] = s1[start + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
