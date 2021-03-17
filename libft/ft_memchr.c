/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:11:01 by gmorange          #+#    #+#             */
/*   Updated: 2021/01/18 15:26:39 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cs;
	unsigned char	cc;

	i = 0;
	cs = (unsigned char *)s;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (cs[i] == cc)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
