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

char	**get_commands(int count, char **parameters)
{
	char	**command;
	int		i;

	command = (char **)malloc(sizeof(char *) * (count + 1));
	if (command == NULL)
		terminate(MALLOC);
	i = 0;
	while (parameters[i] != NULL)
	{
		command[i] = get_command();
		i += 1;
	}
	command[count] = NULL;
	return (command);
}
