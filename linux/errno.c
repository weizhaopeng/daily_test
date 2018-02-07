#include<stdio.h>
#include<string.h>
#include<errno.h>

int main(int argc, char *argv[])
{
	extern int errno;
	FILE *fp;

	fp = fopen("file","r");
	fputc("c"p);


	
	printf("%d\n",errno);
	printf("%s\n",strerror(errno));
	return 0;
}

