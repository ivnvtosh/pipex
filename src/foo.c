/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:18:54 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/24 12:18:58 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(t_data data);
void	child(t_data data);
int		get_out(char *path);
int		get_in(char *path);

void	get_pid(int pid[])
{
	int	check;

	check = pipe(pid);
	if (check == -1)
		terminate(PID);
}

void	foo(t_data data)
{
	pid_t	check;

	get_pid(data.pid.parent);
	check = fork();
	if (check == -1)
	{
		terminate(FORK);
	}
	if (check != 0)
	{
		// parent(data);
		wait(&check);
		if (check != 0)
			terminate(NOTHING);
	}
	else
	{
		// child(data);
		get_out(data.file.out.path);
		dup2(data.pid.parent[0], 1);
		close(data.pid.parent[1]);
		execve(data.command.path[0], data.command.bin[0], data.envp);
		terminate(ERROR);
	}
	check = fork();
	if (check == -1)
	{
		terminate(FORK);
	}
	if (check != 0)
	{
		// parent(data);
		wait(&check);
		if (check != 0)
			terminate(NOTHING);
	}
	else
	{
		// child(data);
		dup2(data.pid.parent[0], 0);
		get_in(data.file.in.path);
		execve(data.command.path[1], data.command.bin[1], data.envp);
		terminate(ERROR);
	}
}
