#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	char *word = NULL;
	if (word)
		printf("word\n");
	if (!word)
		puts("!word");
	word = (char *)malloc(sizeof(char)*10);
	printf("%p\n",word);
	word++;
	printf("%p\n",word);
	return 0;
}
