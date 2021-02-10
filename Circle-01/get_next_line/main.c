#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	char *line;

	printf("start!\n");
	int fd = open("./test.txt", O_RDONLY);

	if (get_next_line(1000, &line) >= 0)
		printf("line : %s\n", line);
	return (0);
}
