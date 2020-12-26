#include "libft.h"

void* ft_memchr(const void* dest, int ch, size_t size)
{
	const unsigned char*	ptr;

	ptr = (const unsigned char*)dest;
	while (size-- > 0)
	{
		if (*ptr == ch)
			return ((void*)ptr);
		++ptr;
	}
	return (NULL);
}
