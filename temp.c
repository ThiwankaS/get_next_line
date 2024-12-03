#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>

char	*ft_strchr(char *str, int c)
{
	size_t	count;

	count = 0;
	while (str && str[count])
	{
		if (str[count] == (char)c)
			return (&str[count]);
		count++;
	}
	return (NULL);
}

int main(void)
{
    char *str1 = "Hello this is a tesing string.\nHere I am trying to extarct a new line.";
    char *result = ft_strchr(str1, '\n');
    printf("Result : %s\n", result);
    return (0);
}
