#include <stdio.h>

int main(void)
{
	char *str1 = "one\ftwo\fthree\ffour";
	char *str2 = "one\ntwo\nthree\nfour";
	char *str3 = "one\rtwo\rthree\rfour";
	char *str4 = "one\ttwo\tthree\tfour";
	char *str5 = "one\vtwo\vthree\vfour";

	printf("str 1 : %s\n",str1);
	printf("str 2 : %s\n",str2);
	printf("str 3 : %s\n",str3);
	printf("str 4 : %s\n",str4);
	printf("str 5 : %s\n",str5);
	return (0);
}
