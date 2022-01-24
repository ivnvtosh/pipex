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

#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	leave(int code);
void	terminate(int code);

char	*get_file(char *path)
{
	char	*s;
	int		fd;

	fd = open(path, S_IREAD);
	if (fd < 0)
		leave(1);
	s = get_next_line(fd);
	if (s == NULL)
		leave(1);
	free(s);
	fd = close(fd);
	if (fd < 0)
		leave(1);
	return (path);
}

t_cmd	get_cmd(char *command)
{
	t_cmd	cmd;
	int		i;

	i = 0;
	while (command[i] != ' ' && command[i] != '\0')
		i++;
	if (ft_strnstr(command, "cat", i))
		cmd.cmd = CAT;
	else if (ft_strnstr(command, "grep", i))
		cmd.cmd = GREP;
	else if (ft_strnstr(command, "wc", i))
		cmd.cmd = WC;
	else if (ft_strnstr(command, "ls", i))
		cmd.cmd = LS;
	cmd.flag = 0;
	cmd.buf = NULL;
	if (command[i] == '\0')
		return (cmd);
	command += i + 1;
	while (command[i] != 32)
		i++;

}

t_data	parser(int count, char **parameters)
{
	t_data	data;

	data.infile = get_file(*parameters++);
	data.cmd1 = get_cmd(*parameters++);
	data.cmd2 = get_cmd(*parameters++);
	data.outfile = get_file(*parameters++);
	return (data);
}
