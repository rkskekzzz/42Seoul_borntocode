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

int pf_utils_ulllen(unsigned long long ull)
{
	int ret;

	ret = 1;
	while((ull /= 16) > 0)
		++ret;
	return (ret);
}

int pf_utils_ilen(int num)
{
	int ret;

	ret = 1;
	while((num /= 10) > 0)
		++ret;
	return (ret);
}
