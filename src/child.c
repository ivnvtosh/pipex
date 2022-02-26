/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:22:23 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/25 14:22:31 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	get_pid(void);
int		get_out(char *path);
int		get_in(char *path);

void	child_1(t_data data, t_cmd cmd)
{
	get_in(data.file.in.path);
	dup2(data.pid.one[1], 1);
	close(data.pid.one[0]);
	close(data.pid.two[0]);
	close(data.pid.two[1]);
	execve(cmd.path, cmd.bin, data.envp);
	terminate("Execve");
}

void	child_2(t_data data, t_cmd cmd)
{
	dup2(data.pid.one[0], 0);
	dup2(data.pid.two[1], 1);
	close(data.pid.one[1]);
	close(data.pid.two[0]);
	execve(cmd.path, cmd.bin, data.envp);
	terminate("Execve");
}

void	child_3(t_data data, t_cmd cmd)
{
	dup2(data.pid.two[0], 0);
	dup2(data.pid.one[1], 1);
	close(data.pid.one[0]);
	close(data.pid.two[1]);
	execve(cmd.path, cmd.bin, data.envp);
	terminate("Execve");
}

void	child_4(t_data data, t_cmd cmd)
{
	dup2(data.pid.one[0], 0);
	get_out(data.file.out.path);
	close(data.pid.one[1]);
	close(data.pid.two[0]);
	close(data.pid.two[1]);
	execve(cmd.path, cmd.bin, data.envp);
	terminate("Execve");
}

// void	child_3_4(t_data data, t_cmd cmd)
// {
// 	dup2(data.pid.two[0], 0);
// 	get_out(data.file.out.path);
// 	close(data.pid.two[1]);
// 	close(data.pid.one[0]);
// 	close(data.pid.one[1]);
// 	execve(cmd.path, cmd.bin, data.envp);
// 	terminate("Execve");
// }