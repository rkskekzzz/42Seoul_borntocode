/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_handler_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:28:50 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pf_type_handler_p(unsigned long long num, t_format *st)
{
	char *ret;
	int len;

	if (st->dot == 1 && num == 0)
		ret = pf_utils_strdup("");
	else if (num == 0)
		ret = pf_utils_strdup("0");
	else
		ret = pf_utils_itoa(num, HEXBASE, 16, st);
	len = pf_utils_strlen(ret) + 2;
	pf_utils_print_rep(' ',!st->minus * st->width - len);
	pf_utils_putstr("0x", 1);
	pf_utils_putstr(ret, 1);
	pf_utils_print_rep(' ',st->minus * st->width - len);
	if (st->width >= len)
		return (st->width);
	return (len );
}
