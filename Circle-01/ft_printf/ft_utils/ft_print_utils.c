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

void pf_utils_init_struct(t_format *st)
{
	ft_memset(st, 0, sizeof(t_format)); // change to ft_memset
}

int	pf_utils_atoi(const char *format, size_t *i)
{
	long long	ret;
	long long	tmp;
	int			is_of;

	ret = 0;
	is_of = 0;
	while (ft_isdigit(format[*i]))
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

void pf_utils_print_rep(char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		++i;
	}
}

char pf_utils_width_char(t_format *st)
{
	if (st->zero == 1 && st->minus != 1)
		return '0';
	else
		return ' ';
}

char* pf_utils_ulltoh(unsigned long long ull)
{
	char *ret;
	size_t i;
	size_t len;

	i = 0;
	if(ull == 0)
		return (ft_strdup("0x0"));
	ret = malloc(pf_utils_ulllen(ull) + 3);
	while (ull > 0)
	{
		ret[i] = HEXBASE[ull % 16];
		ull /= 16;
		++i;
	}
	ft_strlcpy(ret + i, "x0", 3);
	ret[i + 2] = '\0';
	ret = pf_utils_strrev(ret);
	return (ret);
}

char* pf_utils_strrev(char* str)
{
	char *ret;
	size_t i;
	size_t len;

	i = -1;
	if((len = ft_strlen(str)) == 0)
		return ("");
	if (!(ret = malloc(len + 1)))
		return (NULL);
	while(++i < len)
		ret[i] = str[len - i - 1];
	ret[i] = '\0';
	free(str);
	return (ret);
}

char *pf_utils_strldup(const char *src, int wid, int pre, t_format *st)
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

char* pf_utils_itoa_16_base(int num)
{
	int		sign;
	int		i;
	int		cnt;
	char	*buf;

	sign = num < 0 ? 1 : 0;
	i = -1;
	cnt = (int)ft_intlen(num);
	if (!(buf = (char *)malloc(cnt + 1)))
		return (NULL);
	if (sign)
		buf[++i] = '-';
	while (++i < cnt)
	{
		buf[cnt - (!sign) - i] = HEXBASE[ft_abs(num % 10)];
		num /= 10;
	}
	buf[cnt] = '\0';
	return (buf);
}
