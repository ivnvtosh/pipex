/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:02:04 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/24 19:02:05 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../libgnl/libgnl.h"

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include <stdio.h>
# include <string.h> 

typedef struct s_file
{
	char	*path;
	int		fd;
}	t_file;

typedef struct s_files
{
	t_file	out;
	t_file	in;
}	t_files;

typedef struct s_commands
{
	char	***bin;
	char	**path;
}	t_commands;

typedef struct s_pid
{
	int	one[2];
	int	two[2];
}	t_pid;

typedef struct s_data
{
	t_files		file;
	t_pid		pid;
	t_commands	command;
	char		**envp;
}	t_data;

typedef struct s_cmd
{
	char	*path;
	char	**bin;
}	t_cmd;

void	terminate(char *string);

#endif
