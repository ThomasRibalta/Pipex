/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:47:51 by thoribal          #+#    #+#             */
/*   Updated: 2023/11/08 09:50:24 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

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

void	get_last_cmd(char **av, int p_id[2])
{
	char	*tmp;
	int		i;

	i = 0;
	close(p_id[0]);
	while (i != 1)
	{
		write(2, "Here_doc >> ", 12);
		tmp = get_next_line(0, av[2]);
		if (ft_strncmp(tmp, av[2], ft_strlen(av[2])) == 0)
			i++;
		ft_putstr_fd(tmp, p_id[1]);
		free(tmp);
	}
	exit(0);
}

void	pipe2(int i, char **av, char **env)
{
	pid_t	f_id;
	int		p_id[2];
	char	**param;
	char	*path;

	if (pipe(p_id) == -1)
		erreur_mess("Erreur : creation du tunnel de communication.");
	f_id = fork();
	if (f_id == -1)
		erreur_mess("Erreur : creation du sous processus.");
	if (f_id == 0)
	{
		param = ft_split(av[i], ' ');
		path = get_path(env);
		dup2(p_id[1], 1);
		close(p_id[0]);
		execute(param, path, env);
	}
	else
	{
		close(p_id[1]);
		dup2(p_id[0], 0);
	}
}

void	here_doc(char **av)
{
	pid_t	f_id;
	int		p_id[2];

	if (pipe(p_id) == -1)
		erreur_mess("Here_doc >> Erreur : creation du tunnel");
	f_id = fork();
	if (f_id == -1)
		erreur_mess("Here_doc >> Erreur : creation du sous processus.");
	if (f_id == 0)
	{
		get_last_cmd(av, p_id);
	}
	else
	{
		close(p_id[1]);
		dup2(p_id[0], 0);
		wait(NULL);
	}
}

int	main(int ac, char **av, char **env)
{
	int		i;
	int		fd[2];
	char	**param;
	char	*path;

	if (ac < 5)
		erreur_mess("Erreur : nombre d'argument incorrect.");
	fd[1] = open(av[ac - 1], O_RDONLY | O_APPEND | O_WRONLY);
	if (is_here_doc(av, &i, ac, fd))
		here_doc(av);
	while (i < ac - 2)
		pipe2(i++, av, env);
	param = ft_split(av[ac - 2], ' ');
	path = get_path(env);
	dup2(fd[1], 1);
	execute(param, path, env);
}
