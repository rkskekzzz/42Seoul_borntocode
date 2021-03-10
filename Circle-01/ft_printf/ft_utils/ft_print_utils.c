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
	pf_utils_memset(st, 0, sizeof(t_format)); // change to ft_memset
}

void pf_utils_print_rep(char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		pf_utils_putchar(c, 1);
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

char* pf_utils_strrev(char* str)
{
	char *ret;
	size_t i;
	size_t len;

	i = -1;
	if((len = pf_utils_strlen(str)) == 0)
		return ("");
	if (!(ret = malloc(len + 1)))
		return (NULL);
	while(++i < len)
		ret[i] = str[len - i - 1];
	ret[i] = '\0';
	free(str);
	return (ret);
}

