/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:22:57 by gmorange          #+#    #+#             */
/*   Updated: 2021/03/11 15:23:57 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		intlen(int nbr)
{
	int				i;
	unsigned int	unbr;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		unbr = nbr *= -1;
	else
		unbr = nbr;
	while (unbr > 0)
	{
		unbr /= 10;
		i++;
	}
	return (i);
}
