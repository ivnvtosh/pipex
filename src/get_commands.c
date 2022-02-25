/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:03:24 by ccamie            #+#    #+#             */
/*   Updated: 2022/02/24 18:03:27 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_command(char *parameter)
{
	char	**command;

	command = ft_split(parameter, 32);
	if (command == NULL)
		terminate(MALLOC);
	return (command);
}

char	***get_commands(int count, char **parameters)
{
	char	***commands;
	int		i;

	commands = (char ***)malloc(sizeof(char **) * (count + 1));
	if (commands == NULL)
		terminate(MALLOC);
	i = 0;
	while (parameters[i] != NULL)
	{
		commands[i] = get_command(parameters[i]);
		i += 1;
	}
	commands[count] = NULL;
	return (commands);
}
