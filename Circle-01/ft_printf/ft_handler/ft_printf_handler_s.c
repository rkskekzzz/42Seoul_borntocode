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

#include "../ft_printf.h"

int pf_type_handler_s(char* str, t_format *st)
{
	char* ret;
	int len;

	if (!str)
		str = strdup("(null)");
	len = ft_strlen(str);
	if (st->dot == 0)
		st->pre = len;
	if (st->width == -1 ||
		!(ret = pf_utils_strldup(str, pf_max(len, st->width), pf_min(len, st->pre), st)))
		return (-1);
	ft_putstr_fd(ret, 1);
	return (ft_strlen(ret));
}
