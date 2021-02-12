#include <stdio.h>

void sum(int *a)
{
	*a = *a + 9;
	printf("in func a : %d\n", *a);
}

int main(void)
{
	int a = 0;
	printf("out func a : %d\n", a);
	sum(&a);
	printf("out func a : %d\n", a);
}
