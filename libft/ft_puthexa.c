/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:20:56 by gmorange          #+#    #+#             */
/*   Updated: 2021/03/11 15:22:06 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexa(unsigned long int nbr, int lu)
{
	char c;

	if (nbr >= 16)
		ft_puthexa(nbr / 16, lu);
	if (nbr % 16 < 10)
		c = nbr % 16 + 48;
	else if (nbr % 16 >= 10)
		c = nbr % 16 + lu;
	write(1, &c, 1);
}
