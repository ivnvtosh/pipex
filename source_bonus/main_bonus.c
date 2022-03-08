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

#include "../include/pipex.h"

void	ft_here_doc(char *stop);

void	child_n(char *command, char **envp, int fifo_in[2], int fifo_out[2])
{
	pid_t	n;

	n = fork();
	if (n == -1)
	{
		terminate("n = fork()");
	}
	if (n == 0)
	{
		if (close(fifo_in[1]) == -1)
			terminate("if (close(fifo_in[0]) == -1)");
		if (close(fifo_out[0]) == -1)
			terminate("if (close(fifo_out[0]) == -1))");
		child(command, envp, fifo_in[0], fifo_out[1]);
	}
}

void	last(int i, char **argv, char **envp, int fifo[2][2])
{
	if (i % 2 == 0)
	{
		child_last(argv[i + 3], envp, argv[i + 4], fifo[0]);
		ft_close(fifo[0]);
	}
	else
	{
		child_last(argv[i + 3], envp, argv[i + 4], fifo[1]);
		ft_close(fifo[1]);
	}
}

void	child_nnnnn(int count, char **argv, char **envp, int fifo[2][2])
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (i % 2 == 0)
		{
			if (pipe(fifo[1]) == -1)
				terminate("if (pipe(fifo_two) == -1)");
			child_n(argv[i + 3], envp, fifo[0], fifo[1]);
			ft_close(fifo[0]);
		}
		else
		{
			if (pipe(fifo[0]) == -1)
				terminate("if (pipe(fifo_one) == -1)");
			child_n(argv[i + 3], envp, fifo[1], fifo[0]);
			ft_close(fifo[1]);
		}
		i += 1;
	}
	last(i, argv, envp, fifo);
}

int	check_status(int count)
{
	int	*status;
	int	temp;
	int	i;

	status = (int *)malloc(count * sizeof(int));
	if (status == NULL)
		terminate("status = (int *)malloc(argc - 3 * sizeof(int))");
	i = 0;
	while (i < count)
	{
		wait(&status[i]);
		i += 1;
	}
	while (i > 0)
	{
		if (WIFEXITED(status[i - 1]) != 0)
		{
			temp = WEXITSTATUS(status[i - 1]);
			free(status);
			return (temp);
		}
		i -= 1;
	}
	free(status);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	fifo[2][2];

	if (argc <= 4)
		return (1);
	if (pipe(fifo[0]) == -1)
		terminate("if (pipe(fifo) == -1)");
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		ft_here_doc(argv[2]);
		argv++;
		argc--;
		child_first(argv[2], envp, ".here_doc", fifo[0]);
	}
	else
		child_first(argv[2], envp, argv[1], fifo[0]);
	child_nnnnn(argc - 5, argv, envp, fifo);
	unlink(".here_doc");
	return (check_status(argc - 3));
}
