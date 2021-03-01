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
#include "libft/libft.h"

int print_plain(char **format);
int print_specifier();

int	ft_printf(const char* format, ...)
{
	int print_size;
	char *point;
	
	print_size = 0;
	point = format;
	while (*point != 0)
	{
		print_size += print_plain(&point);
		print_size += print_specifier();
	}
	return (print_size);
}

int print_plain(char **point)
{
	int print_size;

	print_size = 0;
	while(**point != '%')
	{
		ft_putchar_fd(**point, 1);
		++point;
		++print_size;
	}
	return (print_size);
}

int print_specifier()
{
	return (0);
}
