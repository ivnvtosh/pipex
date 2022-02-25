/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:01:52 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/24 19:01:53 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_files	get_files(int count, char **parameters);
char	***get_commands(int count, char **parameters);

t_data	parser(int count, char **parameters, char **envp)
{
	t_data	data;

	data.file = get_files(count, parameters);
	data.command = get_commands(count - 2, &parameters[1]);
	data.envp = envp;
	return (data);
}
