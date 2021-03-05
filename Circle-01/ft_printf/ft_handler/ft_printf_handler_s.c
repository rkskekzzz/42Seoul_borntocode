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
	if (st->width == -1)
		return (-1);
	if (st->dot == 0)
		st->pre = len;
	if (!(ret = pf_strldup(str, pf_max(len, st->width), pf_min(len, st->pre), st)))
		return (-1);
	ft_putstr_fd(ret, 1);
	return (ft_strlen(ret));
}

char *pf_strldup(const char *src, int wid, int pre, t_format *st)
{
	char	*dest;

	if (!(dest = (char *)malloc(wid + 1)))
		return (NULL);
	if (st->minus != 1)
	{
		ft_memset(dest, pf_utils_width_char(st), wid - pre);
		ft_strlcpy(dest + (wid - pre), src, wid + 1);
	}
	else
	{
		ft_strlcpy(dest, src, pre + 1);
		ft_memset(dest + pre, pf_utils_width_char(st), wid + 1);
	}
	dest[wid] = '\0';
	return ((char *)dest);
}
