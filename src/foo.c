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

void	foo(t_data data, char **envp)
{
	pid_t	pid;
	char	*s;
	int		p;

	(void)data;
	s = ft_strdup("infile");
	pid = fork();
	if (pid == -1)
	{
		terminate(MALLOC);
	}
	if (pid != 0)
	{
		wait(&p);
	}
	else
	{
		execve("/bin/grep", &s, envp);
		free(s);
	}
}
