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

int	get_out(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		terminate(FD);
	dup2(fd, 0);
	return (fd);
}

int	get_in(char *path)
{
	int	fd;

	fd = open(path, O_WRONLY, O_TRUNC, O_CREAT, 777);
	if (fd == -1)
		terminate(FD);
	dup2(fd, 1);
	return (fd);
}

t_files	get_file(int count, char **parameters)
{
	t_files	file;

	file.out.path = parameters[0];
	file.in.path = parameters[count - 1];
	return (file);
}
