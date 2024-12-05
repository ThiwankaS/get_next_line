#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int fd;
	char *line;

	fd = open("noline.txt", O_RDONLY);

	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while(line)
	{
		printf("%s", line);
		fflush(stdout);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (0);
}
