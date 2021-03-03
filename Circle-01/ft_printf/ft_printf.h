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

// for test header
# include <stdio.h>
# include <string.h>

typedef struct s_format{
	int minus;
	int zero;
	int width;
	int dot;
}	t_format;

int ft_printf(const char* format, ...);
int	pf_printf(const char *format, va_list ap);

//utils
int pf_type_handler(const char* format, size_t *i, va_list ap, t_format *st);
void pf_format_handler(const char* format, size_t *i, t_format *st);

void pf_init_struct(t_format *st);
int	pf_utils_atoi(const char *format, size_t *i);

//handlers
int pf_type_handler_c(const char *format, char ch, t_format *st);
// int pf_type_handler_s(const char *format, char ch);
// int pf_type_handler_p(const char *format, char ch);
// int pf_type_handler_di(const char *format, char ch);
// int pf_type_handler_u(const char *format, char ch);
// int pf_type_handler_x(const char *format, char ch);
// int pf_type_handler_xx(const char *format, char ch);


//ismethoc
int istype(char ch);

// for test function
void pf_print_struct(t_format *st);
int ft_isdigit(char ch);

#endif
