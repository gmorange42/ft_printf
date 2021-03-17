/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 07:16:08 by gmorange          #+#    #+#             */
/*   Updated: 2021/03/11 07:15:08 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flags_uint_two(t_struct *data, int len)
{
	while (data->pres > len)
	{
		print_and_count('0', data);
		data->pres--;
		data->nbr_sp--;
	}
	if (!(data->unsint_to_print == 0 && data->pres == 0))
		ft_putunbr(data->unsint_to_print);
	while (data->nbr_sp > len)
	{
		print_and_count(' ', data);
		data->nbr_sp--;
	}
}

void	print_flags_uint_one(t_struct *data, int len)
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
	if (!(data->unsint_to_print == 0 && data->pres == 0))
		ft_putunbr(data->unsint_to_print);
}

void	print_uint(const char **str, int i, t_struct *data)
{
	int len;

	check_filling(str, data, i);
	data->unsint_to_print = va_arg(data->to_print, int);
	len = ulen(data->unsint_to_print);
	data->ret += len;
	if (data->unsint_to_print == 0 && data->pres == 0)
	{
		data->ret--;
		data->nbr_sp++;
	}
	if (data->sign == 0)
		print_flags_uint_one(data, len);
	else if (data->sign == 1)
		print_flags_uint_two(data, len);
}
