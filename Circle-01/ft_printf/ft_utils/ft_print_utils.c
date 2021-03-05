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

void pf_utils_init_struct(t_format *st)
{
	ft_memset(st, 0, sizeof(t_format)); // change to ft_memset
}

int	pf_utils_atoi(const char *format, size_t *i)
{
	long long	ret;
	long long	tmp;
	int			is_of;

	ret = 0;
	is_of = 0;
	while (ft_isdigit(format[*i]))
	{
		tmp = ret * 10 + (format[*i] - '0');
		if ((((1 << 31) & tmp) ^ ((1 << 31) & ret)) == 0)
			is_of = 1;
		ret = tmp;
		++(*i);
	}
	--(*i);
	if (is_of && ret >= 2147483647)
		return (-1);
	if (is_of && ret < 0)
		return (0);
	return ((int)ret);
}

void pf_utils_print_rep(char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		++i;
	}
}

char pf_utils_width_char(t_format *st)
{
	if (st->zero == 1 && st->minus != 1)
		return '0';
	else
		return ' ';
}

// remove
void pf_print_struct(t_format *st)
{
	printf("minus : %d\n", st->minus);
	printf("zero : %d\n", (*st).zero);
	printf("width : %d\n", (*st).width);
}
