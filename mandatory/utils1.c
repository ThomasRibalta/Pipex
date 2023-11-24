/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:08:48 by thoribal          #+#    #+#             */
/*   Updated: 2023/11/08 09:49:17 by thoribal         ###   ########.fr       */
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
		tmp = ft_strjoine(paths[i], "/");
		join = ft_strjoine(tmp, name);
		free(tmp);
		if (access(join, F_OK | X_OK) == 0)
			return (join);
		free(join);
		i++;
	}
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

void	erreur_mess(char *mess)
{
	ft_putstr_fd("\e[31m", 2);
	ft_putstr_fd(mess, 2);
	ft_putstr_fd("\e[0m", 2);
	exit(0);
}

int	is_here_doc(char **av, int *i, int ac, int fd[2])
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac < 6)
			erreur_mess("Here_doc >> Erreur : nombre d'argument incorrect.");
		*i = 3;
	}
	else
	{
		fd[0] = open(av[1], O_RDONLY);
		*i = 2;
		dup2(fd[0], 0);
	}
	if (!fd[1] || !fd[0])
		erreur_mess("Erreur : ouverture des fichiers");
	if (*i == 3)
		return (1);
	return (0);
}
