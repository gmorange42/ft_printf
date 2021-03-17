/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 07:13:41 by gmorange          #+#    #+#             */
/*   Updated: 2021/03/09 15:31:05 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flags_str_two(t_struct *data, int len)
{
	if (data->pres != 0)
	{
		ft_putnstr(data->str_to_print, len);
	}
	while (data->nbr_sp > len)
	{
		print_and_count(' ', data);
		data->nbr_sp--;
	}
}

void	print_flags_str_one(t_struct *data, int len)
{
	while (data->nbr_sp > len)
	{
		print_and_count(data->filling, data);
		data->nbr_sp--;
	}
	if (data->pres != 0)
		ft_putnstr(data->str_to_print, len);
}

void	it_is_null(t_struct *data)
{
	data->is_null = 1;
	data->str_to_print = ft_strdup("(null)");
}

void	print_str(const char **str, int i, t_struct *data)
{
	int	len;

	len = 0;
	check_filling(str, data, i);
	data->str_to_print = va_arg(data->to_print, char*);
	if (data->str_to_print == NULL)
		it_is_null(data);
	if (data->str_to_print != NULL)
		len = ft_strlen(data->str_to_print);
	if (data->pres >= 0 && data->pres < len)
		len = data->pres;
	data->ret += len;
	if ((data->nbr_sp > 0 || data->pres >= 0) && data->sign == 0)
		print_flags_str_one(data, len);
	else if ((data->nbr_sp - len + 1) >= 0 && data->sign == 1)
		print_flags_str_two(data, len);
	else
	{
		if (data->pres != 0)
			ft_putnstr(data->str_to_print, len);
	}
	if (data->is_null == 1)
		free(data->str_to_print);
}
