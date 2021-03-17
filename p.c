/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 07:15:51 by gmorange          #+#    #+#             */
/*   Updated: 2021/03/11 14:48:51 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flags_add_two(t_struct *data, int len, int lu)
{
	ft_putstr("0x");
	while (data->pres > len - 2)
	{
		print_and_count('0', data);
		data->pres--;
		data->nbr_sp--;
	}
	if (!(data->add_to_print == 0 && data->pres == 0))
		ft_puthexa(data->add_to_print, lu);
	while (data->nbr_sp > len)
	{
		print_and_count(' ', data);
		data->nbr_sp--;
	}
}

void	print_flags_add_one(t_struct *data, int len, int lu)
{
	if (data->filling == '0')
		ft_putstr("0x");
	while (data->nbr_sp > (data->pres + 2) && data->nbr_sp > len)
	{
		print_and_count(data->filling, data);
		data->nbr_sp--;
	}
	if (data->filling == ' ')
		ft_putstr("0x");
	while (data->pres > len - 2)
	{
		print_and_count('0', data);
		data->pres--;
	}
	if (!(data->add_to_print == 0 && data->pres == 0))
		ft_puthexa(data->add_to_print, lu);
}

void	print_add(const char **str, int i, t_struct *data)
{
	int len;
	int lu;

	lu = 87;
	check_filling(str, data, i);
	data->add_to_print = va_arg(data->to_print, unsigned long int);
	len = (hexalen(data->add_to_print) + 2);
	if (data->add_to_print == 0 && data->pres != -1)
		len = 2;
	data->ret += len;
	if (data->sign == 0)
		print_flags_add_one(data, len, lu);
	else if (data->sign == 1)
		print_flags_add_two(data, len, lu);
}
