#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	int *p = malloc(20);
	char c = 'a';
	
	printf("%p\n", p);

	//typeof(c) a;
	char a = 'a';
	printf("%c", a);
	free(p);
	return 0;
}
