#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char *str1, *str2;
	
	str1 = (char *)malloc(sizeof(char)*6);
	str2 = (char *)calloc(2, sizeof(char)*6);

	str2[15] = 'a';
	str1[8]  = 'b';
	for(int i = 0; i < 18; i++) {
		printf("%d\n", str2[i]);
	}
	puts("\n");
	for(int i = 0; i < 10; i++) {
		printf("%d\n", str1[i]);
	}
	free(str1);
	free(str2);
	return 0;
}
