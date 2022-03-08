/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:57:37 by ccamie            #+#    #+#             */
/*   Updated: 2022/03/07 23:57:38 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_first(char *command, char **envp, char *in, int fifo[2])
{
	int		fd;
	pid_t	first;

	first = fork();
	if (first == -1)
	{
		terminate("first = fork()");
	}
	if (first == 0)
	{
		fd = open(in, O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_fd("pipex: ", 2);
			terminate(in);
		}
		if (close(fifo[0]) == -1)
			terminate("if (close(fifo[0]) == -1)");
		child(command, envp, fd, fifo[1]);
	}
}

void	child_last(char *command, char **envp, char *out, int fifo[2])
{
	int		fd;
	pid_t	last;

	last = fork();
	if (last == -1)
		terminate("last = fork()");
	if (last == 0)
	{
		fd = open(out, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd == -1)
			terminate(out);
		if (close(fifo[1]) == -1)
			terminate("if (close(fifo[1]) == -1)");
		child(command, envp, fifo[0], fd);
	}
}
