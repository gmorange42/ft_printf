/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 07:17:14 by gmorange          #+#    #+#             */
/*   Updated: 2021/03/09 09:28:35 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flags_percent_two(t_struct *data, int len)
{
	ft_putchar('%');
	while (data->nbr_sp > len)
	{
		print_and_count(' ', data);
		data->nbr_sp--;
	}
}

void	print_flags_percent_one(t_struct *data, int len)
{
	while (data->nbr_sp > len)
	{
		print_and_count(data->filling, data);
		data->nbr_sp--;
	}
	ft_putchar('%');
}

void	print_percent(const char **str, int i, t_struct *data)
{
	int len;

	check_filling(str, data, i);
	if (data->zero == 1)
		data->filling = '0';
	len = 1;
	data->ret += len;
	if (data->sign == 0)
		print_flags_percent_one(data, len);
	else if (data->sign == 1)
		print_flags_percent_two(data, len);
}
