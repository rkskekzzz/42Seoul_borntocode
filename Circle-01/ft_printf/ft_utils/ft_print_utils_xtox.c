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

int	pf_utils_atoi(const char *format, size_t *i)
{
	long long	ret;
	long long	tmp;
	int			is_of;

	ret = 0;
	is_of = 0;
	while (pf_utils_isdigit(format[*i]))
	{
		tmp = ret * 10 + (format[*i] - '0');
		if ((((1 << 31) & tmp) ^ ((1 << 31) & ret)) == 0)
			is_of = 1;
		ret = tmp;
		++(*i);
	}
	--(*i);
	if (is_of && ret >= 2147483647)
		return (-1);
	if (is_of && ret < 0)
		return (0);
	return ((int)ret);
}

char			*pf_utils_itoa(int num)
{
	int		i;
	int		len;
	int		sign;
	char	*ret;

	len = pf_utils_ilen(num);
	if (!(ret = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	sign = 1;
	if(num < 0)
	{
		sign = 0;
		ret[0] = '-';
	}
	while (++i < len + sign)
	{
		ret[len - i] = BASE[pf_utils_abs(num % 10)];
		num /= 10;
	}
	ret[len] = '\0';
	return (ret);
}

char* pf_utils_itoa_16_base(long long num, const char * hexbase)
{
	int		sign;
	int		i;
	int		len;
	char	*ret;

	if (num == 0)
		return ("");
	len = pf_utils_ulllen(num);
	if (!(ret = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	sign = 1;
	if(num < 0)
	{
		sign = 0;
		ret[0] = '-';
	}
	while (++i < len + sign)
	{
		ret[len - i] = hexbase[pf_utils_abs(num % 16)];
		num /= 16;
	}
	ret[len] = '\0';
	return (ret);
}
