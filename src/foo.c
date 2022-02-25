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

void	parent_process(t_data data, pid_t pid);
void	child_process(t_data data);

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
