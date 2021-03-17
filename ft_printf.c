/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 08:15:32 by gmorange          #+#    #+#             */
/*   Updated: 2021/03/11 14:48:57 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		limit_conversion(char c)
{
	if (c == 's')
		return (1);
	else if ((c == 'd' || c == 'i'))
		return (1);
	else if (c == 'c')
		return (1);
	else if (c == 'p')
		return (1);
	else if (c == 'u')
		return (1);
	else if (c == 'x')
		return (1);
	else if (c == 'X')
		return (1);
	else if (c == '%')
		return (1);
	else if (c == 'n')
		return (1);
	else if (c == '\0')
		return (1);
	else
		return (0);
}

void	check_format(const char **str, int *i, t_struct *data)
{
	int			count;

	count = 0;
	while (limit_conversion((*str)[*i]) != 1)
	{
		count++;
		*i = *i + 1;
	}
	if ((*str)[*i] == 's')
		print_str(str, *i - count, data);
	else if (((*str)[*i] == 'd') || ((*str)[*i] == 'i'))
		print_int(str, *i - count, data);
	else if ((*str)[*i] == 'c')
		print_char(str, *i - count, data);
	else if ((*str)[*i] == 'p')
		print_add(str, *i - count, data);
	else if ((*str)[*i] == 'u')
		print_uint(str, *i - count, data);
	else if ((*str)[*i] == 'x' || (*str)[*i] == 'X')
		print_hexa(str, *i - count, data);
	else if ((*str)[*i] == '%')
		print_percent(str, *i - count, data);
	else if ((*str)[*i] == 'n')
		stock_n(data);
	*i = *i + 1;
}

int		ft_printf(const char *str, ...)
{
	t_struct	data;
	int			i;
	int			j;

	i = 0;
	data.ret = 0;
	va_start(data.to_print, str);
	while (i < (int)ft_strlen(str))
	{
		j = i;
		back_to_zero(&data);
		if (str[i] == '%')
		{
			i++;
			check_format(&str, &i, &data);
		}
		if (i == j)
		{
			print_and_count(str[i], &data);
			i++;
		}
	}
	va_end(data.to_print);
	return (data.ret);
}
