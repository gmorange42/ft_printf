/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxux.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 07:16:57 by gmorange          #+#    #+#             */
/*   Updated: 2021/03/11 10:25:17 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flags_hexa_two(t_struct *data, int len, int lu)
{
	while (data->pres > len)
	{
		print_and_count('0', data);
		data->pres--;
		data->nbr_sp--;
	}
	if (!(data->hexa_to_print == 0 && data->pres == 0))
		ft_puthexa(data->hexa_to_print, lu);
	while (data->nbr_sp > len)
	{
		print_and_count(' ', data);
		data->nbr_sp--;
	}
}

void	print_flags_hexa_one(t_struct *data, int len, int lu)
{
	while (data->nbr_sp > (data->pres) && data->nbr_sp > len)
	{
		print_and_count(data->filling, data);
		data->nbr_sp--;
	}
	while (data->pres > len)
	{
		print_and_count('0', data);
		data->pres--;
	}
	if (!(data->hexa_to_print == 0 && data->pres == 0))
		ft_puthexa(data->hexa_to_print, lu);
}

void	print_hexa(const char **str, int i, t_struct *data)
{
	int len;
	int lu;

	i = check_filling(str, data, i);
	if ((*str)[i] == 'x')
		lu = 87;
	else if ((*str)[i] == 'X')
		lu = 55;
	data->hexa_to_print = va_arg(data->to_print, int);
	len = hexalen(data->hexa_to_print);
	data->ret += len;
	if (data->hexa_to_print == 0 && data->pres == 0)
	{
		data->ret--;
		data->nbr_sp++;
	}
	if (data->sign == 0)
		print_flags_hexa_one(data, len, lu);
	else if (data->sign == 1)
		print_flags_hexa_two(data, len, lu);
}
