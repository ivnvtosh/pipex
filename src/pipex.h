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
# define NOTHING	4

typedef struct s_file
{
	int	out;
	int	in;
}	t_file;

typedef struct s_data
{
	t_file	file;
}	t_data;

void	terminate(int code);

#endif
