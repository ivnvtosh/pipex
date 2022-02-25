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

# define GOOD		0
# define ERROR		1
# define MALLOC		2
# define FD			3
# define PID		4
# define NOTHING	5

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

typedef struct s_data
{
	t_files	file;
	char	***command;
	char	**envp;
}	t_data;

void	terminate(int code);

#endif
