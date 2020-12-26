#include "libft.h"

char*	ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*tmp;

	ptr = (char*)s;
	tmp = 0;
	while (*ptr)
	{
		if (*ptr == c)
			tmp =  ptr;
		ptr++;
	}
	return (tmp);
}
