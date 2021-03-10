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

int pf_type_handler_p(char *str, t_format *st)
{
	int len;
	char *ret;

	str = pf_utils_ulltoh((unsigned long long)str);
	if(!(ret = malloc(ft_strlen(str) + 1)))
		return (0);
	st->zero = 0;
	ret = pf_utils_strldup(str, pf_max(st->width, ft_strlen(str)), ft_strlen(str), st);
	ft_putstr_fd(ret, 1);

	return (ft_strlen(ret));
}
