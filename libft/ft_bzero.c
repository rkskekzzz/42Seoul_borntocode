//42header
#include "libft.h"

void ft_bzero(void* dest, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		*((char*)dest + i) = 0;
}
