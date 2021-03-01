//#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int ft_printf(const char* format, ...);
int print_plain(char *format, int *i);
int print_specifier();

int main(void)
{
	int i = 1;
	double f = 0.1;
	char c = 'c';
	char *s = "string";

	printf("abcde");
	ft_printf("abcde");
}


int	ft_printf(const char* format, ...)
{
	int print_size;
	char *point;
	int i;

	i = 0;
	print_size = 0;
	point = (char *)format;
	while (*point != 0)
	{
		print_size += print_plain(point, &i);
		print_size += print_specifier();
	}
	return (print_size);
}

int print_plain(char *point, int *i)
{
	int print_size;

	print_size = 0;
	while(point[*i] != '%')
	{
		write(1, &point[*i], 1);
		++i;
		++print_size;
	}
	return (print_size);
}

int print_specifier()
{
	return (0);
}
