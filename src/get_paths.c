/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:51:14 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/25 16:51:15 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_path(char **envp)
{
	char	**check;

	while (*envp != NULL && ft_strncmp(*envp, "PATH", 4))
		envp++;
	if (*envp == NULL)
		terminate(ENVP);
	check = ft_split(*envp + 5, ':');
	if (check == NULL)
		terminate(MALLOC);
	return (check);
}

static char	*search_path(char *bin, char **check)
{
	char	*temp;
	char	*temp1;

	temp = NULL;
	while (access(temp, 0) == -1 && *check != NULL)
	{
		free(temp);
		temp1 = ft_strjoin("/", bin);
		if (temp1 == NULL)
			terminate(MALLOC);
		temp = ft_strjoin(*check++, temp1);
		if (temp == NULL)
			terminate(MALLOC);
		free(temp1);
	}
	if (*check == NULL)
		terminate(COMMAND);
	// printf("\x1b[32mfind: %s\x1b[0m\n", temp);
	return (temp);
}

char	**get_paths(int count, char ***bins, char **envp)
{
	char	**check;
	char	**path;
	int		i;

	check = get_path(envp);
	path = (char **)malloc(sizeof(char *) * (count + 1));
	if (path == NULL)
		terminate(MALLOC);
	i = 0;
	while (bins[i] != NULL)
	{
		path[i] = search_path(bins[i][0], check);
		i += 1;
	}
	path[count] = NULL;
	return (path);
}
