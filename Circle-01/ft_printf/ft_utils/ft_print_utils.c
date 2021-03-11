/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:27:45 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void pf_utils_init_struct(t_format *st)
{
	pf_utils_memset(st, 0, sizeof(t_format)); // change to ft_memset
	st->pre = -1;
}

void pf_utils_print_rep(char c, int n)
{
	int i;

	i = -1;
	while (++i < n)
		pf_utils_putchar(c, 1);
}

char pf_utils_width_char(t_format *st)
{
	if (st->zero == 1 && st->minus != 1)
		return ('0');
	else
		return (' ');
}

