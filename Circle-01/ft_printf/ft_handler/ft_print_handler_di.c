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

#include "../ft_printf.h"

int pf_type_handler_di(int num, t_format *st)
{
	char *ret;
	int len;

	ret = pf_utils_itoa(num);
	len = pf_utils_strlen(ret);
	if (st->dot == 0)
		st->pre = len;
	ret = pf_utils_strldup(ret, pf_max(st->width, len), pf_min(st->pre, len), st);
	pf_utils_putstr(ret, 1);
	return (pf_utils_strlen(ret));
}
