/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:42:39 by ccamie            #+#    #+#             */
/*   Updated: 2022/03/07 20:44:34 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	child(char *command, char **envp, int in, int out);

static void	child_first(char *command, char **envp, char *in, int fifo[2])
{
	int		fd;
	pid_t	first;

	first = fork();
	if (first == -1)
	{
		perror("first = fork()");
		exit(1);
	}
	if (first == 0)
	{
		fd = open(in, O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_fd("pipex: ", 2);
			perror(in);
			exit(1);
		}
		if (close(fifo[0]) == -1)
		{
			perror("if (close(fifo[0]) == -1)");
			exit(1);
		}
		child(command, envp, fd, fifo[1]);
	}
}

static void	child_last(char *command, char **envp, char *out, int fifo[2])
{
	int		fd;
	pid_t	last;

	last = fork();
	if (last == -1)
	{
		perror("last = fork()");
		exit(1);
	}
	if (last == 0)
	{
		fd = open(out, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd == -1)
		{
			perror(out);
			exit(1);
		}
		if (close(fifo[1]) == -1)
		{
			perror("if (close(fifo[1]) == -1)");
			exit(1);
		}
		child(command, envp, fifo[0], fd);
	}
}

static void	ft_close(int fifo[2])
{
	if (close(fifo[0]) == -1)
	{
		perror("if (close(fifo[0]) == -1)");
		exit(1);
	}
	if (close(fifo[1]) == -1)
	{
		perror("if (close(fifo[1]) == -1)");
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		status[2];
	int		fifo[2];

	if (argc != 5)
		return (1);
	if (pipe(fifo) == -1)
	{
		perror("if (pipe(fifo) == -1)");
		exit(1);
	}
	child_first(argv[2], envp, argv[1], fifo);
	child_last(argv[3], envp, argv[4], fifo);
	ft_close(fifo);
	wait(&status[0]);
	wait(&status[1]);
	if (WIFEXITED(status[1]) != 0)
		return (WEXITSTATUS(status[1]));
	if (WIFEXITED(status[0]) != 0)
		return (WEXITSTATUS(status[0]));
	return (0);
}
