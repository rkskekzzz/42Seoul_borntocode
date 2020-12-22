//42 header
#include "libft.h"

void*	ft_memset(void* dest, int value, size_t size)
{
	size_t	i;

	i = -1;
	while(++i < size)
		*((char*)dest + i) = value;
	return (dest);
}
