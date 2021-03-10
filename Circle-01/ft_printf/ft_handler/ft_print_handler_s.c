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

#include "../ft_printf.h"

int pf_type_handler_s(char* str, t_format *st)
{
	char* ret;
	int len;

	if (!str)
		str = pf_utils_strdup("(null)");
	len = pf_utils_strlen(str);
	if (st->dot == 0)
		st->pre = len;
	if (st->width == -1 ||
		!(ret = pf_utils_strldup(str, pf_max(len, st->width), pf_min(len, st->pre), st)))
		return (-1);
	pf_utils_putstr(ret, 1);
	return (pf_utils_strlen(ret));
}
