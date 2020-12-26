#include "libft.h"

int		ft_toupper(int c)
{
	if (ft_isalpha(c) == 2)
		c -= 32;
	return (c);
}
