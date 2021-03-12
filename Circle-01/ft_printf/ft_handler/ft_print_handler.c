/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:28:31 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pf_type_handler(const char *format, size_t *i, va_list ap, t_format *st)
{
	if (format[*i] == 'c')
		return (pf_type_handler_c(va_arg(ap, int), st));
	if (format[*i] == 's')
		return (pf_type_handler_s(va_arg(ap, char*), st));
	if (format[*i] == 'p')
		return (pf_type_handler_p(va_arg(ap, unsigned long long), st));
	if (format[*i] == 'd' || format[*i] == 'i')
		return (pf_type_handler_num(va_arg(ap, int), st, BASE, 10));
	if (format[*i] == 'u')
		return (pf_type_handler_num(va_arg(ap, unsigned int), st, BASE, 10));
	if (format[*i] == 'x')
		return (pf_type_handler_num(va_arg(ap, unsigned int), st, HEXBASE, 16));
	if (format[*i] == 'X')
		return (pf_type_handler_num(va_arg(ap, unsigned int), st, HEXBASEL, 16));
	if (format[*i] == '%')
		return (pf_type_handler_c('%', st));
	return (0);
}

void pf_format_handler(const char *format, size_t *i, va_list ap, t_format *st)
{
	if (format[*i] == '\0')
		--(*i);
	else if(format[*i] == '-')
		st->minus = 1;
	else if(st->dot == 0 && format[*i] == '0')
		st->zero = 1;
	else if(st->dot == 0 && format[*i] == '*')
		st->width = pf_asterisk_wid_handler(va_arg(ap, int), st);
	else if(st->dot == 0 && pf_utils_isdigit(format[*i]))
		st->width = pf_utils_atoi(format, i);
	else if(format[*i] == '.')
		st->dot = 1;
	else if(st->dot == 1 && pf_utils_isdigit(format[*i]))
		st->pre = pf_utils_atoi(format, i);
	else if(st->dot == 1 && format[*i] == '*')
		st->pre = pf_asterisk_pre_handler(va_arg(ap, int), st);
}

int pf_asterisk_wid_handler(int num, t_format *st)
{
	if (num < 0)
	{
		st->minus = 1;
		num *= -1;
	}
	return (num);
}

int pf_asterisk_pre_handler(int num, t_format *st)
{
	if (num < 0)
	{
		st->dot = 0;
		return (-2);
	}
	return (num);
}

