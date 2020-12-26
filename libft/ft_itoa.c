/*
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
size_t ft_intlen(int n)
{
	size_t len;

	len = n < 0 ? 1 : 0;
	while (1)
	{
		++len;
		if (!(n / 10))
			break;
		n /= 10;
	}
	return (len);
}

char *ft_itoa(int n)
{
	int neg;
	int i;
	int cnt;
	char *buf;

	neg = n < 0 ? 1 : 0;
	i = neg ? 0 : -1;
	cnt = (int)ft_intlen(n);
	printf("%d\n", n);
	if (!(buf = (char *)malloc(sizeof(char)* (cnt + 1))))
		return (NULL);
	memset(buf, 0, cnt + 1);
	if (neg)
		buf[0] = '-';
	while (++i < cnt)
	{
		buf[cnt - (!neg) - i] = "0123456789"[n % 10];
		n /= 10;
	}
	buf[cnt] = '\0';
	return (buf);
}

int main(void)
{
	printf("%s", ft_itoa(-123));
	return (0);
}
*/
