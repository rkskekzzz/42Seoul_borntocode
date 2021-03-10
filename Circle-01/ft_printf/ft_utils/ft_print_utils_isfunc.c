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

//cspdiuxX
int pf_utils_istype(char ch)
{
	return (ch == 'c' || ch == 's' || ch == 'p' || ch == 'd' || ch == 'i' || \
		ch == 'u' || ch == 'x' || ch == 'X' || ch == '%');
}

int	pf_utils_isdigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}
