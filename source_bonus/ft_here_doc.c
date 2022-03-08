/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:34:21 by ccamie            #+#    #+#             */
/*   Updated: 2022/03/08 11:34:23 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*get_next_line(int fd);

void	ft_here_doc(char *stop)
{
	char	*string;
	ssize_t	length;
	int		fd;

	fd = open(".here_doc", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		terminate("fd = open(\".here_doc\", O_WRONLY | O_CREAT, 0644)");
	string = get_next_line(STDIN_FILENO);
	while (string != NULL && ft_strncmp(string, stop, ft_strlen(stop)) != 0)
	{
		length = ft_strlen(string);
		if (write(fd, string, length) != length)
			terminate("if (write(fd, string, length) != length)");
		free(string);
		string = get_next_line(STDIN_FILENO);
	}
	free(string);
	if (close(fd) == -1)
		terminate("if (close(fd) == -1)");
}
