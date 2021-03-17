/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 07:14:19 by gmorange          #+#    #+#             */
/*   Updated: 2021/03/11 11:15:42 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	negative(t_struct *data)
{
	if (data->int_to_print < 0)
	{
		data->unsint_to_print = data->int_to_print * -1;
		data->zero = 1;
	}
	else
		data->unsint_to_print = data->int_to_print;
}

void	print_flags_id_two(t_struct *data, int len)
{
	if (data->int_to_print < 0)
		print_and_count('-', data);
	while (data->pres > len)
	{
		print_and_count('0', data);
		data->pres--;
		data->nbr_sp--;
	}
	if (!(data->int_to_print == 0 && data->pres == 0))
		ft_putunbr(data->unsint_to_print);
	while (data->nbr_sp > len)
	{
		print_and_count(' ', data);
		data->nbr_sp--;
	}
}

void	print_flags_id_one(t_struct *data, int len)
{
	if (data->int_to_print < 0 && data->filling == '0')
		print_and_count('-', data);
	while (data->nbr_sp > (data->pres) && data->nbr_sp > len)
	{
		print_and_count(data->filling, data);
		data->nbr_sp--;
	}
	if (data->int_to_print < 0 && data->filling == ' ')
		print_and_count('-', data);
	while (data->pres > len)
	{
		print_and_count('0', data);
		data->pres--;
	}
	if (!(data->int_to_print == 0 && data->pres == 0))
		ft_putunbr(data->unsint_to_print);
}

void	print_int(const char **str, int i, t_struct *data)
{
	int len;

	check_filling(str, data, i);
	data->int_to_print = va_arg(data->to_print, int);
	negative(data);
	len = intlen(data->unsint_to_print);
	data->ret += len;
	if (data->int_to_print < 0)
		data->nbr_sp--;
	if (data->int_to_print == 0 && data->pres == 0)
	{
		data->ret--;
		data->nbr_sp++;
	}
	if (data->sign == 0)
		print_flags_id_one(data, len);
	else if (data->sign == 1)
		print_flags_id_two(data, len);
}
