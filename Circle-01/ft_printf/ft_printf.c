/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:27:33 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	//ft_printf("%-010c%c", 'a','b');
	// ft_printf("%c",'c');

	char *a = NULL;
	char *k = "hello";
	int a1,b,c,d;
	/**  hancler c **/
//	printf("%-7.3s\n","hello");
//	ft_printf("%7.3s","hello");
	/**  hancler s **/
	printf("real : %.p\n", NULL);
	ft_printf("make : %.p", NULL);
	printf("\nreal : %20p\n", &k);
	ft_printf("make : %20p", &k);
	printf("\nreal : %07.1x\n", 42);
	ft_printf("make : %07.1x", 42);
	printf("\nreal : %020.3u\n", 2141483999);
	ft_printf("make : %020.3u", 2141483999);
	printf("\nreal : %-020.3u\n", 12345);
	ft_printf("make : %-020.3u", 12345);
//	printf("%0.4p\n",&k);
//	printf("%0.4p\n",&k);
	//ft_printf("%0.2p",'c');
//	b = printf("%s", NULL);
//	printf("b : %d", b);
	//c = ft_printf("%7.3s",a);
	/**  hancler pc **/
//	printf("%%\n");
//	ft_printf("%%");
	/**  hancler p **/
//	printf("%-14p\n", "hello");
//	ft_printf("%p", "hello");
//	printf("\nb : %d c : %d", b, c);
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
			while (!pf_utils_istype(format[++i]))
				pf_format_handler(format, &i, ap, &st);
			if (pf_utils_istype(format[i]))
				print_size += pf_type_handler(format, &i, ap, &st);
		}
		else
		{
			pf_utils_putchar(format[i], 1);
			++print_size;
		}
		++i;
	}
	return (print_size);
}
