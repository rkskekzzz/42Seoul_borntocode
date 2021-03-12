/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_handler_di.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:28:41 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pf_type_handler_di(int num, t_format *st)
{
	char *ret;
	char *tmp;
	int len;

	if (num < 0)
		st->pre += 1;
	if (st->zero == 1 && st->dot == 0 && st->minus != 1)
		st->pre = st->width;
	if (num == 0 && st->dot == 1 && st->pre <= 0)
		ret = pf_utils_strdup("");
	else
		ret = pf_utils_itoa(num, BASE, 10, st);
	len = pf_utils_strlen(ret);
	st->zero = 0;
	tmp = pf_utils_strldup(ret, pf_max(st->width, len), len, st);
	if(ret != NULL)
		free(ret);
	return (pf_utils_freestr(&tmp));
}