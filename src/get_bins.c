/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:51:23 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/25 16:51:25 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_bin(char *parameter)
{
	char	**command;

	command = ft_split(parameter, 32);
	if (command == NULL)
		terminate(MALLOC);
	return (command);
}

char	***get_bins(int count, char **parameters)
{
	char	***bin;
	int		i;

	bin = (char ***)malloc(sizeof(char **) * (count + 1));
	if (bin == NULL)
		terminate(MALLOC);
	i = 0;
	while (parameters[i] != NULL)
	{
		bin[i] = get_bin(parameters[i]);
		i += 1;
	}
	bin[count] = NULL;
	return (bin);
}
