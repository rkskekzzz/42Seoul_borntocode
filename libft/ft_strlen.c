#include "libft.h"

size_t ft_strlen(const char* str)
{
	size_t	i;

	i = -1;
	while (*(++i + str))
		;
	return (i);
}

