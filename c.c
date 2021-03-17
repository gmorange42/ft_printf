/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 07:14:48 by gmorange          #+#    #+#             */
/*   Updated: 2021/03/09 10:51:59 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flags_char_two(t_struct *data, int len)
{
	ft_putchar(data->char_to_print);
	while (data->nbr_sp > len)
	{
		print_and_count(' ', data);
		data->nbr_sp--;
	}
}

void	print_flags_char_one(t_struct *data, int len)
{
	while (data->nbr_sp > len)
	{
		print_and_count(data->filling, data);
		data->nbr_sp--;
	}
	ft_putchar(data->char_to_print);
}

void	print_char(const char **str, int i, t_struct *data)
{
	int len;

	check_filling(str, data, i);
	if (data->zero == 1)
		data->filling = '0';
	data->char_to_print = va_arg(data->to_print, int);
	len = 1;
	data->ret += len;
	if ((data->nbr_sp > 0 || data->pres >= 0) && data->sign == 0)
		print_flags_char_one(data, len);
	else if ((data->nbr_sp - len + 1) >= 0 && data->sign == 1)
		print_flags_char_two(data, len);
	else
		ft_putchar(data->char_to_print);
}
