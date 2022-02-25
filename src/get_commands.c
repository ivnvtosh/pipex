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

char	***get_bins(int count, char **parameters);
char	**get_paths(int count, char ***bins, char **envp);

t_commands	get_commands(int count, char **parameters, char **envp)
{
	t_commands	command;

	command.bin = get_bins(count, parameters);
	command.path = get_paths(count, command.bin, envp);
	return (command);
}
