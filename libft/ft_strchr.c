/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:35:12 by gmorange          #+#    #+#             */
/*   Updated: 2021/01/19 15:19:42 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	cc;

	i = 0;
	cc = (unsigned char)c;
	while ((cc != s[i] && s[i]))
		i++;
	if (cc == '\0')
		return ((char *)s + i);
	if (s[i] == '\0')
		return (NULL);
	return ((char *)s + i);
}
