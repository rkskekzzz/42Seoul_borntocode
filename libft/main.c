#include "libft.h"

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

	char s3[10] = "1234567890";
	char *c;
	printf("%c", '\n');
	c = (char*)ft_memchr(s3, '4', 3);
	if (c != NULL) printf("%c", *c);
	else printf("NULL");
	printf("%c", '\n');
	c = (char*)memchr(s3, '4', 3);
	if (c != NULL) printf("%c", *c);
	else printf("NULL");

	char ptr1[5] = "1234";
	char ptr2[5] = "1233";
	printf("\n%d", ft_memcmp(ptr1, ptr2, 5));
	printf("\n%d", memcmp(ptr1, ptr2, 5));


	char len[10] = "abcde";
	printf("\n%d", ft_strlen(len));
	printf("\n%d", strlen(len));

	char lcpy[4] = "abc";
	char lcpy2[10] = "zzzzzzzzz";
	printf("\n%d", ft_strlcpy(lcpy2,lcpy,2));
	printf("\n%d", strlcpy(lcpy2,lcpy,2));
}
