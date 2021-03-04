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

#include "ft_printf.h"

int pf_type_handler_s(char* str, t_format *st)
{
	char* ret;
	int len;

	len = ft_strlen(str);
	if (!str)
		ft_strdup("(null)");
	if (st->width == -1)
		return (-1);
	if (st->dot == 0)
		st->pre = len;
	if (ret = strldup(str, pf_max(len, st->width), pf_min(len), st->pre)))
		return (-1);
	ft_putstr_fd(ret, 1);
	return (ft_strlen(ret));
}

char *ft_strldup(const char *src, int wid, int pre)
{
	// minus옵션 처리@@!
	char	*dest;

	if (!(dest = (char *)malloc(wid + 1)))
		return (NULL);
	ft_strlcpy(dest, src, pre + 1);
	ft_memset(dest + pre, 32, wid - pre);
	dest[wid] = '\0';
	return ((char *)dest);
}
