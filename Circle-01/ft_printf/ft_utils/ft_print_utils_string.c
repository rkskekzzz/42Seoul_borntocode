/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:26:30 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/10 15:28:11 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pf_utils_strlen(const char *str)
{
	size_t	i;

	i = -1;
	while (*(++i + str))
		;
	return (i);
}

size_t	pf_utils_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	while (src[i])
		++i;
	return (i);
}

char	*pf_utils_strdup(const char *src)
{
	char	*dest;
	size_t	len;

	len = pf_utils_strlen(src);
	if (!(dest = (char *)malloc(len + 1)))
		return (NULL);
	pf_utils_strlcpy(dest, src, len + 1);
	return ((char *)dest);
}

char *pf_utils_strldup(const char *src, int wid, int pre, t_format *st)
{
	char	*dest;

	if (!(dest = (char *)malloc(wid + 1)))
		return (NULL);
	if (st->minus != 1)
	{
		pf_utils_memset(dest, pf_utils_width_char(st), wid - pre);
		pf_utils_strlcpy(dest + (wid - pre), src, wid + 1);
	}
	else
	{
		pf_utils_strlcpy(dest, src, pre + 1);
		pf_utils_memset(dest + pre, pf_utils_width_char(st), wid + 1);
	}
	dest[wid] = '\0';
	return ((char *)dest);
}

char	*pf_utils_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = pf_utils_strlen(s1);
	j = pf_utils_strlen(s2);
	if (!(dest = (char *)malloc(i + j + 1)))
		return (NULL);
	pf_utils_strlcpy(dest, s1, i + 1);
	pf_utils_strlcpy(dest + i, s2, j + 1);
	return (dest);
}


