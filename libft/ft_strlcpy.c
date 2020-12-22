#include "libft.h"

size_t	ft_strlcpy(char* dest, const char* src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && *src)
		{
			*dest = *src;
			++dest;
			++src;
			++i;
		}
		*dest = '\0';
	}
	while (*src)
	{
		++src;
		++i;
	}
	return (i);
}
