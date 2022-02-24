/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:59:38 by ccamie            #+#    #+#             */
/*   Updated: 2021/10/12 17:52:28 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s)
{
	char	*sd;
	size_t	slen;

	slen = ft_strlen(s) + 1;
	sd = (char *)malloc(sizeof(char) * (slen));
	if (sd == NULL)
		return (NULL);
	ft_memcpy(sd, s, slen);
	return (sd);
}
