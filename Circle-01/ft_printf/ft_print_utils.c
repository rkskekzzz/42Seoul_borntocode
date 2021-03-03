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

int pf_type_handler(const char* format, size_t *i, va_list ap)
{
	if (format[*i] == 'c')
		return (pf_type_handler_c(format, va_arg(ap, int)));
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

void pf_format_handler(const char* format, size_t *i)
{
	if (format[*i] == '\0')
		--i;
	else if(format[*i] == '-')
		++i;
	else if(format[*i] != '.') // && isdigit libft
		++i;
	else if(format[*i] == '.')
		++i;
	else if(format[*i] == '.') // && isdigit libft
		++i;
	else
		++i;
}

void pf_init_struct(t_format *st)
{
	memset(st, 0, sizeof(t_format)); // change to ft_memset
}
