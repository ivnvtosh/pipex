/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 06:42:05 by ccamie            #+#    #+#             */
/*   Updated: 2022/01/13 06:43:08 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_max(float n1, float n2)
{
	if (n1 < 0)
		n1 *= -1;
	if (n2 < 0)
		n2 *= -1;
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}
