#include "libft.h"

void*	ft_memccpy(void* dest, const void* src, int ch, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
	{
		*((char*)dest + i) = *((char*)src + i);
		if (*((char*)src + i) == ch)
			break ;
	}
	if (++i == size)
		return (0);
	return (i + dest);
}
