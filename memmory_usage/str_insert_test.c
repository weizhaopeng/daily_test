#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char *str, *str1;
	str1 = str = (char *)malloc(sizeof(char)*20);
	str[0] = 't';
	str[1] = 65;
	str1 = "nihao a ";
	printf("%p\n",str);
	printf("%p\n",str1);
	for (int i = 0; i < 20; i++)
		printf("%c\n",str[i]);
	printf("%s\n",str);
	free(str);
	return 0;
}
