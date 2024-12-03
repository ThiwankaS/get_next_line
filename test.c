#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int fd;
	char *line;

	fd = open("a.txt", O_RDONLY);

	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while(line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
