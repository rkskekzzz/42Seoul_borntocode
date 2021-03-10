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
int pf_va_handler(int num, t_format *st);

//handler_c
int pf_type_handler_c(char ch, t_format *st);
//handler_s
int pf_type_handler_s(char *str, t_format *st);
//handler_p
int pf_type_handler_p(unsigned long long ull, t_format *st);
//handler_di
int pf_type_handler_di(int num, t_format *st);
//handler_u
int pf_type_handler_u(unsigned int num, t_format *st);
//handler_x & X
int pf_type_handler_x(unsigned long long ull, t_format *st, const char * hb);
//handler_pc
int pf_type_handler_pc(void);

//utils
void pf_utils_init_struct(t_format *st);
void pf_utils_print_rep(char c, int n);
char pf_utils_width_char(t_format *st);


//utils_xtox
int	pf_utils_atoi(const char *format, size_t *i);
char* pf_utils_itoa(int num);
char* pf_utils_untoa_16_base(unsigned long long num, const char * base, int bs);


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
char 	*pf_utils_strldup(const char *src, int wid, int pre, t_format *st);
char	*pf_utils_strjoin(char const *s1, char const *s2);


// utils_lib
void	*pf_utils_memset(void *dest, int value, size_t size);
void	pf_utils_putstr(char *s, int fd);
void	pf_utils_putchar(char c, int fd);
#endif
