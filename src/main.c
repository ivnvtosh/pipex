/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:01:47 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/24 19:01:48 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int count, char **parameters, char **envp);

int	main(int argc, char **argv, char **envp)
{
	if (argc <= 3)
		return (NOTHING);
	pipex(--argc, ++argv, envp);
	return (GOOD);
}
