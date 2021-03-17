/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 08:25:02 by gmorange          #+#    #+#             */
/*   Updated: 2021/03/11 14:49:47 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef	struct			s_struct
{
	va_list				to_print;
	int					nbr_sp;
	int					sign;
	char				filling;
	int					zero;
	int					pres;
	unsigned long int	ret;
	int					int_to_print;
	unsigned char		char_to_print;
	unsigned int		hexa_to_print;
	unsigned long int	add_to_print;
	char				*str_to_print;
	unsigned int		unsint_to_print;
	int					is_null;
	int					*n;
}						t_struct;

int						ft_printf(const char *str, ...);
void					print_and_count(char c, t_struct *data);
void					back_to_zero(t_struct *data);
void					char_data(char arg_to_print, const char **str, int i);
int						check_filling(const char **str, t_struct *data, int i);
void					print_int(const char **str, int i, t_struct *data);
void					print_str(const char **str, int i, t_struct *data);
void					print_char(const char **str, int i, t_struct *data);
void					print_uint(const char **str, int i, t_struct *data);
void					print_hexa(const char **str, int i, t_struct *data);
void					print_add(const char **str, int i, t_struct *data);
void					print_percent(const char **str, int i, t_struct *data);
void					stock_n(t_struct *data);
#endif
