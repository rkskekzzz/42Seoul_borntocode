/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 12:08:01 by suhshin           #+#    #+#             */
/*   Updated: 2021/01/02 16:57:39 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int			ft_atoi(const char *s)
{
	int			sign;
	int			len;
	long long	ret;
	long long	tmp;

	sign = 1;
	ret = 0;
	len = 0;
	while (ft_isspace(*s))
		++s;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (ft_isdigit(*s))
	{
		tmp = ret * 10 + (*s++ - '0');
		if (++len > 19 || tmp < ret)
			return (sign < 0 ? 0 : -1);
		ret = tmp;
	}
	return ((int)ret * sign);
}
#include <stdio.h>
#include <string.h>
int main(void)
{
	printf("%d\n", atoi("21464736489"));
}
