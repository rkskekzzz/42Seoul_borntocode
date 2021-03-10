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
# include "libft/libft.h"
// for test header
# include <stdio.h>
# include <string.h>
# define HEXBASE "0123456789abcdef"
# define HEXBASEX "0123456789ABCDEF"

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

//handler_c
int pf_type_handler_c(char ch, t_format *st);
//handler_s
int pf_type_handler_s(char *str, t_format *st);
char *pf_utils_strldup(const char *src, int wid, int pre, t_format *st);

int pf_type_handler_p(char *str, t_format *st);
int pf_type_handler_di(int num, t_format *st);
// int pf_type_handler_u(const char *format, char ch);
// int pf_type_handler_x(const char *format, char ch);
// int pf_type_handler_xx(const char *format, char ch);
int pf_type_handler_pc(void);

//utils
void pf_utils_init_struct(t_format *st);
void pf_utils_print_rep(char c, int n);
char pf_utils_width_char(t_format *st);
int	pf_utils_atoi(const char *format, size_t *i);
char *pf_utils_ptr_to_str(char *str);

char* pf_utils_ulltoh(unsigned long long ull);
int pf_utils_ulllen(unsigned long long ull);
char* pf_utils_strrev(char* str);
char* pf_utils_itoa(int num);
int pf_utils_ilen(int num);
char* pf_utils_itoa_16_base(int num);
//isfunc
int istype(char ch);

//cal
int pf_max(int a, int b);
int pf_min(int a, int b);

#endif
