#include "libft.h"

int		ft_atoi(const char *str)
{
	int		n;
	int		sign;
	char	*ptr;

	sign = 1;
	n = 0;
	ptr = (char*)str;
	if(*ptr == '-')
	{
		sign = -1;
		++ptr;
	}
	while (*ptr)
	{
		n += 10 * n + *ptr - '0';
		++ptr;
	}
	return (n * sign);
}
