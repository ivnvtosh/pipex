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

#include "../libft/libft.h"
#include "pipex.h"
#include <stdlib.h>

void	leave(int code)
{
	if (code)
		ft_putstr_fd("Error\n", 2);
	exit(code);
}

void	terminate(int code)
{
	leave(code);
}
