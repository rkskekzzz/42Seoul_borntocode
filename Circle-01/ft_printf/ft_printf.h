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
int pf_type_handler_s(char *ch, t_format *st);
char *pf_strldup(const char *src, int wid, int pre, t_format *st);

int pf_type_handler_p(char *ch, t_format *st);
// int pf_type_handler_di(const char *format, char ch);
// int pf_type_handler_u(const char *format, char ch);
// int pf_type_handler_x(const char *format, char ch);
// int pf_type_handler_xx(const char *format, char ch);
int pf_type_handler_pc(void);

//utils
void pf_utils_init_struct(t_format *st);
void pf_utils_print_rep(char c, int n);
char pf_utils_width_char(t_format *st);
int	pf_utils_atoi(const char *format, size_t *i);

//isfunc
int istype(char ch);

//cal
int pf_max(int a, int b);
int pf_min(int a, int b);

// for test function
void pf_print_struct(t_format *st);

#endif
