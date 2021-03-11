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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

// for test header
# include <stdio.h>
# include <string.h>
# define BASE "0123456789"
# define HEXBASE "0123456789abcdef"
# define HEXBASEL "0123456789ABCDEF"

typedef struct s_format{
	int minus;
	int zero;
	int width;
	int dot;
	int pre;
}	t_format;

int ft_printf(const char* format, ...);
int	pf_printf(const char *format, va_list ap);

//handler
int pf_type_handler(const char *format,size_t *i, va_list ap, t_format *st);
void pf_format_handler(const char *format,size_t *i, va_list ap, t_format *st);
int pf_asterisk_wid_handler(int num, t_format *st);
int pf_asterisk_pre_handler(int num, t_format *st);

int pf_type_handler_c(char ch, t_format *st);
int pf_type_handler_s(char *str, t_format *st);
int pf_type_handler_p(unsigned long long num, t_format *st);
int pf_type_handler_di(int num, t_format *st);
int pf_type_handler_x(unsigned int num, t_format *st, const char * base, int bs);

//utils
void pf_utils_init_struct(t_format *st);
void pf_utils_print_rep(char c, int n);
char pf_utils_width_char(t_format *st);
void	*pf_utils_memcpy(void *dest, const void *src, size_t size);

//utils_xtox
int	pf_utils_atoi(const char *format, size_t *i);
char* pf_utils_itoa(int num, t_format *st);
char* pf_utils_untoa_16_base(unsigned long long num, const char * base, int bs, t_format *st);


// utils_ isfunc
int pf_utils_istype(char ch);
int	pf_utils_isdigit(char ch);

// utils_cal
int pf_max(int a, int b);
int pf_min(int a, int b);
int pf_utils_numlen(long long num, int base);
long long	pf_utils_abs(long long n);

// utils_string
size_t	pf_utils_strlen(const char *str);
size_t	pf_utils_strlcpy(char *dst, const char *src, size_t dstsize);
char	*pf_utils_strdup(const char *src);
char 	*pf_utils_strldup(char *src, int wid, int pre, t_format *st);
char	*pf_utils_strjoin(char *s1, char *s2);


// utils_lib
void	*pf_utils_memset(void *dest, int value, size_t size);
void	pf_utils_putstr(char *s, int fd);
void	pf_utils_putchar(char c, int fd);
int pf_utils_freesrc(char **dest, char *src);
int pf_utils_freestr(char **str);
#endif
