/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:56:20 by gmorange          #+#    #+#             */
/*   Updated: 2021/01/27 10:59:59 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_toitoa(int j, unsigned int temp, unsigned int n, int sign)
{
	char *nbr;

	if (sign == -1)
		j++;
	if ((int)temp >= 0)
	{
		j++;
		while (temp >= 10)
		{
			temp = temp / 10;
			j++;
		}
		if (!(nbr = malloc(sizeof(char) * (j + 1))))
			return (NULL);
		nbr[j] = '\0';
		j--;
	}
	while (j >= 0)
	{
		nbr[j] = (n % 10) + 48;
		n = n / 10;
		j--;
	}
	return (nbr);
}

char		*ft_itoa(int n)
{
	int		sign;
	char	*nbr;

	sign = 0;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	if (!(nbr = ft_toitoa(0, n, n, sign)))
		return (NULL);
	if (sign == -1)
		nbr[0] = '-';
	return (nbr);
}
