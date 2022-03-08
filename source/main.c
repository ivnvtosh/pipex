/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:01:07 by ccamie            #+#    #+#             */
/*   Updated: 2022/03/07 20:43:57 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	status[2];
	int	fifo[2];

	if (argc != 5)
		return (1);
	if (pipe(fifo) == -1)
		terminate("if (pipe(fifo) == -1)");
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
