/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:52:13 by gmorange          #+#    #+#             */
/*   Updated: 2021/01/25 12:43:01 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkoccurrence(const char *s1, const char *set)
{
	int i;
	int count;
	int start;

	i = 0;
	count = 0;
	start = 0;
	while (s1[i] && start == count)
	{
		if (ft_strchr(set, s1[i]) != NULL)
			start++;
		i++;
		count++;
	}
	return (start);
}

static int	ft_checkoccurrencerev(const char *s1, const char *set)
{
	int i;
	int count;
	int end;

	i = ft_strlen(s1) - 1;
	count = 0;
	end = 0;
	while (s1[i] && end == count)
	{
		if (ft_strchr(set, s1[i]) != (NULL))
			end++;
		i--;
		count++;
	}
	return (end);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	int		i;
	char	*trim;

	if (!s1)
		return (NULL);
	start = ft_checkoccurrence(s1, set);
	end = ft_checkoccurrencerev(s1, set);
	len = ft_strlen(s1) - start - end;
	if (len <= 0)
		len = 0;
	i = 0;
	if (!(trim = malloc((sizeof(char) * len) + 1)))
		return (NULL);
	while (i < len)
	{
		trim[i] = s1[start];
		i++;
		start++;
	}
	trim[i] = '\0';
	return (trim);
}
