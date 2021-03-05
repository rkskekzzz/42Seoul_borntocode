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

int main(void)
{
	//ft_printf("%-010c%c", 'a','b');
	// ft_printf("%c",'c');

	char *a = NULL;
	int a1,b,c,d;
	/**  hancler c **/
//	printf("%-7.3s\n","hello");
//	ft_printf("%7.3s","hello");
	/**  hancler s **/
	b = printf("%7s\n",a);
	//c = ft_printf("%7.3s",a);
	/**  hancler pc **/
//	printf("%%\n");
//	ft_printf("%%");
	/**  hancler p **/
//	printf("%-14p\n", "hello");
//	ft_printf("%p", "hello");
	printf("\nb : %d c : %d", b, c);
	return (0);
}

int		ft_printf(const char* format, ...)
{
	int print_size;
	va_list ap;

	va_start(ap, format);
	print_size = pf_printf(format, ap);
	va_end(ap);
	if (print_size < 0)
		return (-1);
	return (print_size);
}

int		pf_printf(const char *format, va_list ap)
{
	size_t i;
	int print_size;
	t_format st;

	i = 0;
	print_size = 0;
	while (format[i] != '\0')
	{
		pf_utils_init_struct(&st);
		if (format[i] == '%')
		{
			while (!istype(format[++i]))
				pf_format_handler(format, &i, ap, &st);
			if (istype(format[i]))
				print_size += pf_type_handler(format, &i, ap, &st);
		}
		else
		{
			write(1, &format[i], 1);
			++print_size;
		}
		++i;
	}
	return (print_size);
}
