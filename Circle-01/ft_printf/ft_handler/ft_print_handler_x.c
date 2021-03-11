/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_handler_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:29:17 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pf_type_handler_x(unsigned long long num, t_format *st, const char * base)
{
	char *ret;
	int len;

	if (num == 0 && st->dot == 1 && st->pre == 0)
		ret = pf_utils_strdup("");
	else
		ret = pf_utils_untoa_16_base(num, base, 16, st);
	len = pf_utils_strlen(ret);
//	st->zero = 0;
	ret = pf_utils_strldup(ret, pf_max(st->width, len), len, st);
	pf_utils_putstr(ret, 1);
	return (pf_utils_strlen(ret));
}
