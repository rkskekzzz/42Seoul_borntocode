#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	char			*d_start;
	char			*s_start;
	size_t	p_length;
	size_t	s_length;

	d_start = dest;
	s_start = src;
	while (size && *dest)
	{
		++dest;
		--size;
	}
	while (*src)
		++src;
	p_length = (size_t)(dest - d_start);
	s_length = (size_t)(src - s_start);
	if (!size)
		return (p_length + s_length);
	while (*s_start && size-- > 1)
		*dest++ = *s_start++;
	*dest = '\0';
	return (p_length + s_length);
}
