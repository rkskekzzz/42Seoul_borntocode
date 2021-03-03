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

void print_rep(char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		++i;
	}
}

int pf_type_handler_c(const char* format, char ch, t_format *st)
{

	if (st->width > 1)
	{
		if (st->minus == 1)
		{
			write(1, &ch, 1);
			print_rep(' ', st->width - 1);
		}
		else
		{
			print_rep(' ', st->width - 1);
			write(1, &ch, 1);
		}
		return (st->width);
	}
	write(1, &ch, 1);
	return (1);
}
