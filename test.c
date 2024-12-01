#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int fd;
	char *line;
	int res;

	fd = open("sample.txt", O_RDONLY);

	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	printf("%s", line);
	if(line)
	{
		res = ft_has_newline(line);
		printf("\n res : %d\n", res);
	}
	free(line);
	close(fd);
	return (0);
}
