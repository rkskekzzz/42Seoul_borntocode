#include <stdio.h>
#include <string.h>

char *ft_strcpy(char *dst, const char *src)
{
	char *cp = dst;
	while (*cp++ = *src++)
		;
	return dst;
}

int main(void){
	char dest[5] = "hi";
	char src[3] = "wo";

	printf("%s\n", ft_strcpy(dest, src));
}

