/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:36:00 by gmorange          #+#    #+#             */
/*   Updated: 2021/01/19 15:20:53 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	cc;

	i = ft_strlen(s);
	cc = (unsigned char)c;
	while (cc != s[i] && i >= 0)
		i--;
	if (i < 0)
		return (NULL);
	return ((char *)s + i);
}
