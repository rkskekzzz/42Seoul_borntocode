/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_handler_s.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:29:02 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pf_type_handler_s(char* str, t_format *st)
{
	char* ret;
	int len;

	if (st->dot == 1 && st->pre <= 0)
		ret = pf_utils_strdup("");
	else if (!str)
		ret = pf_utils_strdup("(null)");
	else
		ret = pf_utils_strdup(str);
	len = pf_utils_strlen(ret);
	if (st->pre < 0)
		st->pre = len;
	if (st->dot == 1)
		len = pf_min(st->pre, len);
	pf_utils_print_rep(' ', !st->minus * st->width - len);
	write(1, ret, len);
	pf_utils_print_rep(' ', st->minus * st->width - len);
	return (pf_utils_free_len(&ret, pf_max(st->width, len)));
}
