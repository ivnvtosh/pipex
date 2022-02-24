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

void	parent_process(t_data data, pid_t pid)
{
	(void)data;
	(void)pid;
	wait(&pid);
	if (pid != 0)
		terminate(NOTHING);
}

int	get_out(char *path);
int	get_in(char *path);

void	child_process(t_data data)
{
	char	**cmd;

	data.file.out.fd = get_out(data.file.out.path);
	data.file.in.fd = get_in(data.file.in.path);
	cmd = (char **)malloc(sizeof(char *) * 3);
	if (cmd == NULL)
		terminate(MALLOC);
	cmd[0] = "grep";
	cmd[1] = "H";
	cmd[2] = NULL;
	execve("/usr/bin/grep", cmd, data.envp);
	terminate(PID);
}

void	foo(t_data data)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		terminate(PID);
	}
	if (pid != 0)
	{
		parent_process(data, pid);
	}
	else
	{
		child_process(data);
	}
}
