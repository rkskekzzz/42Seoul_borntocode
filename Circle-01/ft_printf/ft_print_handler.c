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

#include "ft_printf.h"

int pf_type_handler(const char* format, size_t *i, va_list ap, t_format *st)
{
	if (format[*i] == 'c')
		return (pf_type_handler_c(format, va_arg(ap, int), st));
	if (format[*i] == 's')
		//return (pf_type_handler_c(format));
	if (format[*i] == 'p')
		//return (pf_type_handler_c(format));
	if (format[*i] == 'd' || format[*i] == 'i')
		//return (pf_type_handler_c(format));
	if (format[*i] == 'u')
		//return (pf_type_handler_c(format));
	if (format[*i] == 'x')
		//return (pf_type_handler_c(format));
	if (format[*i] == 'X')
		//return (pf_type_handler_c(format));
	return (-1);
	return (0);
}

void pf_format_handler(const char* format, size_t *i, t_format *st)
{
	if (format[*i] == '\0')
		--i;
	else if(format[*i] == '-')
		st->minus = 1;
	else if(format[*i] == '0')
		st->zero = 1;
	else if(format[*i] != '.' && ft_isdigit(format[*i])) // change to ft_isdigit
		st->width = pf_utils_atoi(format, i);
	else if(format[*i] == '.')
		st->dot = 1;
	else if(format[*i] == '.') // && isdigit libft
		++i;
	else
		++i;
	//pf_print_struct(st);
}
