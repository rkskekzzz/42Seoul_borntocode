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

int pf_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int pf_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int pf_utils_ulllen(long long num)
{
	size_t	ret;

	ret = 1;
	if (num < 0)
		++ret;
	num = pf_utils_abs(num);
	while ((num /= 16) > 0)
		++ret;
	return (ret);
}

int pf_utils_ilen(long long num)
{
	size_t	ret;

	ret = 1;
	if (num < 0)
		++ret;
	num = pf_utils_abs(num);
	while ((num /= 10) > 0)
		++ret;
	return (ret);
}

long long	pf_utils_abs(long long num)
{
	if (num < 0)
		return (-num);
	return (num);
}
