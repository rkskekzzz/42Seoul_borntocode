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

	if (!str)
		ft_strdup("(null)");
	if (st->width == -1)
		return (-1);
	if (st->dot == 0)
		st->pre = 2147483647;
	if (ret error check)
	ret = strldup(str, max(ft_strlen(str), st->width), min(ft_strlen, st->pre))
	ft_putstr_fd(ret, 1);
	return (ft_strlen(ret));
}

char *ft_strldup(const char *src, int len)
{
	// 맥스만큼 할당후 lcpy memset
	char	*dest;

	if (len == 0 || len > ft_strlen(src))
		return (ft_strdup(src));
	if (!(dest = (char *)malloc(len + 1)))
		return (NULL);
	ft_strlcpy(dest, src, len + 1);
	return ((char *)dest);
}
