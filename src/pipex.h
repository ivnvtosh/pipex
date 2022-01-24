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

# define CAT	0
# define GREP	1
# define WC		2
# define LS		3

# include <stdio.h>

typedef struct s_cmd
{
	int		cmd;
	int		flag;
	char	*buf;
}	t_cmd;

typedef struct s_data
{
	char	*infile;
	char	*outfile;
	t_cmd	cmd1;
	t_cmd	cmd2;
}	t_data;

#endif
