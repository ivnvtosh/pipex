/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:19:23 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/24 11:19:27 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_in(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		terminate("outfile");
	}
	dup2(fd, 0);
	fd = close(fd);
	if (fd == -1)
		terminate("outfile");
	return (fd);
}

int	get_out(char *path)
{
	int	fd;

	fd = open(path, O_WRONLY, O_TRUNC, O_CREAT, 0644);
	if (fd == -1)
		terminate("infile");
	dup2(fd, 1);
	fd = close(fd);
	if (fd == -1)
		terminate("infile");
	return (fd);
}

static void	check_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		terminate("outfile");
	fd = close(fd);
	if (fd == -1)
		terminate("outfile");
}

t_files	get_files(int count, char **parameters)
{
	t_files	file;

	check_file(parameters[count - 1]);
	file.out.path = parameters[count - 1];
	file.in.path = parameters[0];
	return (file);
}
