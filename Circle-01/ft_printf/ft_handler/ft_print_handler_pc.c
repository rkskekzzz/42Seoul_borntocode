/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_handler_pc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:28:56 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pf_type_handler_pc(t_format *st)
{
	if (st->width > 1)
	{
		if (st->minus == 1)
		{
			pf_utils_putchar('%', 1);
			pf_utils_print_rep(pf_utils_width_char(st), st->width - 1);
		}
		else
		{
			pf_utils_print_rep(pf_utils_width_char(st), st->width - 1);
			pf_utils_putchar('%', 1);
		}
		return (st->width);
	}
	pf_utils_putchar('%', 1);
	return (1);
}
