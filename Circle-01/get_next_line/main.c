#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	char *line;

	printf("start!\n");
	int fd = open("./test.txt", O_RDONLY);

	//if (get_next_line(fd, &line) >= 0)
	//	printf("line : %s\n", line);
	printf("%d\n",get_next_line(fd, &line));
	printf("line : %s\n", line);
	printf("%d\n",get_next_line(fd, &line));
	printf("line : %s\n", line);
	printf("%d\n",get_next_line(fd, &line));
	printf("line : %s\n", line);
	printf("%d\n",get_next_line(fd, &line));
	printf("line : %s\n", line);
	printf("%d\n",get_next_line(fd, &line));
	printf("line : %s\n", line);
	printf("%d\n",get_next_line(fd, &line));
	printf("line : %s\n", line);
	return (0);
}
