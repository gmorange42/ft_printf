/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:06:30 by gmorange          #+#    #+#             */
/*   Updated: 2021/01/27 12:37:55 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	int				i;

	i = len - 1;
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (!(dst) && !(src))
		return (0);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (i >= 0)
	{
		cdst[i] = csrc[i];
		i--;
	}
	return (cdst);
}
