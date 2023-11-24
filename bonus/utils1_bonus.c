/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:08:48 by thoribal          #+#    #+#             */
/*   Updated: 2023/11/04 15:07:56 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	*get_path(char **env)
{
	while (ft_strncmp("PATH=", *env, 5) != 0 && *env && env)
		env++;
	return (*env + 5);
}

char	*check_path(char **paths, char *name)
{
	char	*join;
	char	*tmp;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		join = ft_strjoin(tmp, name);
		free(tmp);
		if (access(join, F_OK | X_OK) == 0)
			return (join);
		free(join);
		i++;
	}
	perror("does");
	return (NULL);
}

void	free_all(char **tab)
{
	char	**tmp;

	tmp = tab;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(tmp);
}
