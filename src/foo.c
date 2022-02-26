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
void	child_1(t_data data, t_cmd cmd);
void	child_2(t_data data, t_cmd cmd);
void	child_3(t_data data, t_cmd cmd);
void	child_4(t_data data, t_cmd cmd);
int		get_out(char *path);
int		get_in(char *path);

void	get_pid(int pid[])
{
	int	check;

	check = pipe(pid);
	if (check == -1)
		terminate(NULL);
}

void	foo(t_data data)
{
	t_cmd	cmd;
	pid_t	child1;
	pid_t	child2;
	pid_t	child3;
	pid_t	child4;
	int		status;

	get_pid(data.pid.one);
	get_pid(data.pid.two);



	child1 = fork();
	if (child1 == -1)
	{
		terminate("Fork");
	}
	if (child1 == 0)
	{
		cmd.path = data.command.path[0];
		cmd.bin = data.command.bin[0];
		ft_putstr_fd("grep 1\n", 1);
		child_1(data, cmd);
	}



	child2 = fork();
	if (child2 == -1)
	{
		terminate("Fork");
	}
	if (child2 == 0)
	{
		cmd.path = data.command.path[1];
		cmd.bin = data.command.bin[1];
		ft_putstr_fd("grep 2\n", 1);
		child_2(data, cmd);
	}



	child3 = fork();
	if (child3 == -1)
	{
		terminate("Fork");
	}
	if (child3 == 0)
	{
		cmd.path = data.command.path[2];
		cmd.bin = data.command.bin[2];
		ft_putstr_fd("grep 3\n", 1);
		child_3(data, cmd);
	}



	child4 = fork();
	if (child4 == -1)
	{
		terminate("Fork");
	}
	if (child4 == 0)
	{
		cmd.path = data.command.path[3];
		cmd.bin = data.command.bin[3];
		ft_putstr_fd("grep 4\n", 1);
		child_4(data, cmd);
	}


	close(data.pid.one[0]);
	close(data.pid.one[1]);
	close(data.pid.two[0]);
	close(data.pid.two[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
	ft_putstr_fd("gg\n", 1);
	waitpid(child3, &status, 0);
	waitpid(child4, &status, 0);
}
