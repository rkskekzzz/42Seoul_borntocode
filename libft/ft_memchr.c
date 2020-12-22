#include "libft.h"

void* ft_memchr(const void* dest, int ch, size_t size)
{
	char*	ptr;

	ptr = (char*)dest;
	while (ptr < ((char*)dest + size))
	{
		if (*ptr == ch)
			return (ptr);
		++ptr;
	}
	return (0);
}
