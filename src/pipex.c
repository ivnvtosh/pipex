/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:01:58 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/24 19:01:59 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_data	parser(int count, char **parameters, char **envp);
void	foo(t_data data);

void	pipex(int count, char **parameters, char **envp)
{
	t_data	data;

	data = parser(count, parameters, envp);
	// foo(data);
}
