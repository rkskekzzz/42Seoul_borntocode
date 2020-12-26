#include "libft.h"

int		ft_tolower(int c)
{
	if (ft_isalpha(c) == 1)
		c += 32;
	return (c);
}
