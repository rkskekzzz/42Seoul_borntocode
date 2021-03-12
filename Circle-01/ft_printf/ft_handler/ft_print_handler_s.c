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
	char* tmp;
	int len;

	if (st->dot == 1 && st->pre == -1)
		ret = pf_utils_strdup("");
	else if (!str)
		ret = pf_utils_strdup("(null)");
	else
		ret = pf_utils_strdup(str);
	len = pf_utils_strlen(ret);
	if (st->pre <= -1)
		st->pre = len;
	if (st->dot == 1)
		len = pf_min(st->pre, len);
	len =  pf_max(st->width, len);
	tmp = pf_utils_strldup(ret, len, pf_min(pf_utils_strlen(ret), st->pre), st);
	if(ret != NULL)
		free(ret);
	return (pf_utils_freestr(&tmp));
}
