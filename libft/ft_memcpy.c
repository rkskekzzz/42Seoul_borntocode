#include "libft.h"

void*	ft_memcpy(void* dest, const void* src, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		*((char*)dest + i) = *((char*)src + i);
	return (dest);
}
