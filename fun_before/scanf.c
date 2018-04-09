#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main (void)
{
	int 	 a;
	char 	 b;
	char 	 c[10], *buf = NULL;
	double   d;
	uint32_t f;
	uint16_t g;
	size_t   h;

	buf = malloc(sizeof(char)*10);

	/*
	scanf("%*d%s%lf", c, &d);
	printf("%s%lf", c, d);
	*/
	/*
	sscanf("nihao 3345", "%s%d", c, &f);
	printf("%s%d", c, f);
	*/
	sscanf("nihaowojiao", "%5s", buf);
	printf("%s", buf);
	
	if (buf)
		free(buf);
	return 0;
}
