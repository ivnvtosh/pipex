/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:02:15 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/24 19:02:17 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	terminate(char *string)
{
	if (string == NULL)
	{
		exit(0);
	}
	else
	{
		perror(string);
		exit(1);
	}
}
