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

void	child(t_data data)
{
	// data.pid.child = get_pid();
	get_out(data.file.out.path);
	get_in(data.file.in.path);
	execve(data.command.path[0], data.command.bin[0], data.envp);
	terminate(ERROR);
}
