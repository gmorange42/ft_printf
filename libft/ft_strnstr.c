/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:45:34 by gmorange          #+#    #+#             */
/*   Updated: 2021/01/29 11:49:29 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack + i);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			while ((haystack[i] == needle[j]) && i < len && haystack[i])
			{
				i++;
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)haystack + (i - j));
			if (haystack[i] != needle[j])
				j = 0;
		}
		else
			i++;
	}
	return (NULL);
}
