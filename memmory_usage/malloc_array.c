#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main (int argc, char *argv[])
{
	extern int errno;
	char *word,*array;

	word  = (char *)malloc(sizeof(char)*20);
	array = "wojiaoweizhaopeng";
	for(int i=0 ; i<argc ; i++)
	{
		printf("%c\n",array[i]);
		printf("%s\n",argv[i]);
		if(!strcmp(argv[i], "--help"))
			puts("neef help\n");
		if(!strcmp(argv[i], "-c"))
		{
			for(int j=0 ; j<(int)argv[i+1] ; j++)
				printf("%c",word[j]);
			puts("\n");
		}
	}
	free(word);
	return errno;
}
