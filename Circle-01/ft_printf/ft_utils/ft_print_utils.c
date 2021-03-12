/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:27:45 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void pf_utils_init_struct(t_format *st)
{
	pf_utils_memset(st, 0, sizeof(t_format)); // change to ft_memset
	st->pre = -1;
}

void pf_utils_print_rep(char c, int n)
{
	char *tmp;

	if (n < 0)
		return ;
	tmp = malloc(n + 1);
	if(!tmp)
		return ;
	pf_utils_memset(tmp, c, n);
	tmp[n] = '\0';
	pf_utils_putstr(tmp, 1);
	free(tmp);
}

char pf_utils_width_char(t_format *st)
{
	if (st->zero == 1 && st->minus != 1)
		return ('0');
	return (' ');
}


void	*pf_utils_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = -1;
	if (dest != src && size)
		while (++i < size)
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
	return (dest);
}
