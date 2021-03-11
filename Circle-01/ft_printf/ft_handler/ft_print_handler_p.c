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
	int len;
	char *ret;

	if (st->dot == 1 && num == 0)
		ret = pf_utils_strdup("");
	else if (num == 0)
		ret = pf_utils_strdup("0");
	else
		ret = pf_utils_untoa_16_base(num, HEXBASE, 16, st);
	ret = pf_utils_strjoin("0x", ret);
	len = pf_utils_strlen(ret);
	st->zero = 0;
//	ret = pf_utils_strldup(ret, pf_max(st->width, len), len, st);
	pf_utils_freesrc(&ret, pf_utils_strldup(ret, pf_max(st->width, len), len, st));
	pf_utils_putstr(ret, 1);
	return (pf_utils_freestr(&ret));
}
