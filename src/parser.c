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

t_file	get_file(int count, char **parameters);

t_data	parser(int count, char **parameters)
{
	t_data	data;

	data.file = get_file(count, parameters);
	return (data);
}
