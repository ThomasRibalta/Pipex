/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:47:51 by thoribal          #+#    #+#             */
/*   Updated: 2023/11/08 09:46:49 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	execute(char **param, char *path, char **env)
{
	char	**paths;
	char	*path1;

	paths = ft_split(path, ':');
	path1 = check_path(paths, param[0]);
	if (!path1)
	{
		free_all(paths);
		free_all(param);
		erreur_mess("Erreur : chemin d'acces incorrecte.");
	}
	if (execve(path1, param, env) == -1)
	{
		free_all(paths);
		free_all(param);
		erreur_mess("Erreur : execution impossible.");
	}
	free_all(paths);
	free_all(param);
	free(path1);
}

void	child(char **av, char **env, int p_id[2])
{
	char	**param;
	char	*path;
	int		fd_in;

	param = ft_split(av[2], ' ');
	path = get_path(env);
	fd_in = open(av[1], O_RDONLY, 0777);
	if (fd_in == -1)
	{
		free_all(param);
		erreur_mess("Erreur : ouverture du fichier.");
	}
	close(p_id[0]);
	dup2(p_id[1], 1);
	dup2(fd_in, 0);
	execute(param, path, env);
}

void	parent(char **av, char **env, int p_id[2])
{
	char	**param;
	char	*path;
	int		fd_out;

	param = ft_split(av[3], ' ');
	path = get_path(env);
	fd_out = open(av[4], O_RDONLY | O_WRONLY | O_TRUNC, 0777);
	if (fd_out == -1)
	{
		free_all(param);
		erreur_mess("Here_doc >> Erreur : creation du tunnel");
	}
	close(p_id[1]);
	dup2(p_id[0], 0);
	dup2(fd_out, 1);
	execute(param, path, env);
}

int	main(int ac, char **av, char **env)
{
	int		p_id[2];
	pid_t	f_id;

	if (ac != 5)
		erreur_mess("Erreur : nombre d'argument incorrect.");
	if (pipe(p_id) == -1)
		erreur_mess("Erreur : creation du tunnel.");
	f_id = fork();
	if (f_id == -1)
		erreur_mess("Erreur : creation du sous processus.");
	if (f_id == 0)
		child(av, env, p_id);
	parent(av, env, p_id);
}
