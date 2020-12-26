#include "libft.h"

int		ft_memcmp(const void* ptr1, const void* ptr2, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size && (*((char*)ptr1 + i) == *((char*)ptr2 + i)))
		;
	return (*((char*)ptr1 + i) - *((char*)ptr2 + i));
}

