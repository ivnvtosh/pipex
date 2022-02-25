/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:22:23 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/25 14:22:31 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_out(char *path);
int	get_in(char *path);

void	child_process(t_data data)
{
	char	**cmd;

	get_out(data.file.out.path);
	get_in(data.file.in.path);
	cmd = *data.command;
	execve("/usr/bin/grep", cmd, data.envp);
	terminate(PID);
}
