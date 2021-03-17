/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:59:59 by gmorange          #+#    #+#             */
/*   Updated: 2021/01/18 14:58:24 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*dest;
	unsigned char	*srce;
	size_t			i;

	a = (unsigned char)c;
	dest = (unsigned char *)dst;
	srce = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (srce[i] == a)
		{
			dest[i] = srce[i];
			return ((void *)dest + i + 1);
		}
		dest[i] = srce[i];
		i++;
	}
	return (NULL);
}
