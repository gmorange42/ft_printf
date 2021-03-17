/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_untils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:56:30 by gmorange          #+#    #+#             */
/*   Updated: 2021/03/11 11:15:35 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pres(const char **str, t_struct *data, int i)
{
	if ((*str)[i] == '.')
	{
		i++;
		data->pres++;
		if ((*str)[i] == '*')
		{
			i++;
			data->pres = va_arg(data->to_print, int);
		}
		while ((*str)[i] >= '0' && ((*str)[i] <= '9'))
		{
			data->pres = (data->pres * 10) + ((*str)[i] - 48);
			i++;
		}
	}
	if (data->sign == 1 || data->pres >= 0)
		data->filling = ' ';
	return (i);
}

int		check_nbr_sp(const char **str, t_struct *data, int i)
{
	while ((*str)[i] >= '0' && ((*str)[i] <= '9'))
	{
		data->nbr_sp = (data->nbr_sp * 10) + ((*str)[i] - 48);
		i++;
	}
	return (i);
}

int		check_filling(const char **str, t_struct *data, int i)
{
	while (((*str)[i] == '0') || ((*str)[i] == '-') || ((*str)[i] == '*'))
	{
		if ((*str)[i] == '-')
			data->sign = 1;
		if ((*str)[i] == '0')
		{
			data->zero = 1;
			data->filling = '0';
		}
		if ((*str)[i] == '*')
		{
			data->nbr_sp = va_arg(data->to_print, int);
			if (data->nbr_sp < 0)
			{
				data->sign = 1;
				data->nbr_sp *= -1;
			}
		}
		i++;
	}
	i = check_nbr_sp(str, data, i);
	i = pres(str, data, i);
	return (i);
}

void	back_to_zero(t_struct *data)
{
	data->nbr_sp = 0;
	data->sign = 0;
	data->filling = ' ';
	data->zero = 0;
	data->pres = -1;
	data->int_to_print = 0;
	data->char_to_print = 0;
	data->hexa_to_print = 0;
	data->add_to_print = 0;
	data->str_to_print = NULL;
	data->unsint_to_print = 0;
	data->is_null = 0;
	data->n = 0;
}

void	print_and_count(char c, t_struct *data)
{
	write(1, &c, 1);
	data->ret++;
}
