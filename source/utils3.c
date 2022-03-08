/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:01:14 by ccamie            #+#    #+#             */
/*   Updated: 2022/03/07 20:01:15 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_free(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i] != NULL)
		free(pointer[i++]);
	free(pointer);
}

void	terminate(const char *string)
{
	perror(string);
	exit(1);
}

void	ft_close(int fifo[2])
{
	if (close(fifo[0]) == -1)
		terminate("if (close(fifo[0]) == -1)");
	if (close(fifo[1]) == -1)
		terminate("if (close(fifo[1]) == -1)");
}
