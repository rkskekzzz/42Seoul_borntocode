#include "libft.h"
#include <stdio.h>
#include <string.h>
int main(void){
	int memset_test[10];
	int bzero_test[10];

	ft_memset(memset_test, 0, sizeof(memset_test));
	for(int i =  0 ; i < 10 ; i++)
		printf("%d ", memset_test[i]);

	printf("%c", '\n');
	ft_bzero(bzero_test, sizeof(bzero_test));
	for(int i =  0 ; i < 10 ; i++)
		printf("%d ", bzero_test[i]);

	char dest[5] = "he";
	char src[5] = "wo";

	printf("%c", '\n');
	ft_memcpy(dest, src, 2);
	for(int i = 0 ; i < 2 ; i++)
		printf("%c ", dest[i]);

	char s[20] = "1234567890";
	printf("%c", '\n');
	ft_memmove(s+4, s+2, 6);
	for (int i = 0 ; i < 10; i++)
		printf("%c ", s[i]);
	char s2[20] = "1234567890";
	printf("%c", '\n');
	memmove(s2+4, s2+2, 6);
	for (int i = 0 ; i < 10; i++)
		printf("%c ", s2[i]);

}
