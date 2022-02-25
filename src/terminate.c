/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:02:15 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/24 19:02:17 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	terminate(int code)
{
	if (code == ERROR)
		ft_putstr_fd("Error\n", 2);
	else if (code == MALLOC)
		ft_putstr_fd("Error: malloc\n", 2);
	else if (code == FD)
		ft_putstr_fd("Error: fd\n", 2);
	else if (code == ENVP)
		ft_putstr_fd("Error: envp\n", 2);
	else if (code == COMMAND)
		ft_putstr_fd("Error: command\n", 2);
	else if (code == PID)
		ft_putstr_fd("Error: pid\n", 2);
	else if (code == FORK)
		ft_putstr_fd("Error: fork\n", 2);
	exit(code);
}
