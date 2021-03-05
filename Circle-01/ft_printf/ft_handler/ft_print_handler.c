/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/02/28 16:13:43 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int pf_type_handler(const char *format,size_t *i, va_list ap, t_format *st)
{
	if (format[*i] == 'c')
		return (pf_type_handler_c(va_arg(ap, int), st));
	if (format[*i] == 's')
		return (pf_type_handler_s(va_arg(ap, char*), st));
	if (format[*i] == 'p')
		;
		//return (pf_type_handler_c(format));
	if (format[*i] == 'd' || format[*i] == 'i')
		;
		//return (pf_type_handler_c(format));
	if (format[*i] == 'u')
		;
		//return (pf_type_handler_c(format));
	if (format[*i] == 'x')
		;
		//return (pf_type_handler_c(format));
	if (format[*i] == 'X')
		;
		//return (pf_type_handler_c(format));
	if (format[*i] == '%')
		return (pf_type_handler_pc());
	return (0);
}



void pf_format_handler(const char *format,size_t *i, va_list ap, t_format *st)
{
	if (format[*i] == '\0')
		--(*i);
	if(format[*i] == '-')
		st->minus = 1;
	if(st->dot == 0 && format[*i] == '0')
		st->zero = 1;
	if(format[*i] == '*')
		st->width = va_arg(ap, int);
	if(st->dot == 0 && ft_isdigit(format[*i]))
		st->width = pf_utils_atoi(format, i);
	if(format[*i] == '.')
		st->dot = 1;
	if(st->dot == 1 && ft_isdigit(format[*i]))
		st->pre = pf_utils_atoi(format, i);
}
