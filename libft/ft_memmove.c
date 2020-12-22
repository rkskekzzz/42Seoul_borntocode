#include "libft.h"

void*	ft_memmove(void* dest, const void* src, size_t size)
{
	size_t	i;

	i = -1;
	if (!(dest <= src || (char*)dest >= ((char*)src + size)))
		while (++i < size)
			*((char*)dest + size - 1 - i) = *((char*)src + size - 1 - i);
	return (dest);
}
