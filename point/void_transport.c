#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a;
	int b;
} str;

int main (int argc, char *argv[])
{
	void *p;
	str  *st, *st1;

	st 	  = (str *)malloc(sizeof(str));
	st->a = 23;
	st->b = 24;
	p 	  = st;
	st1	  = (str *)p;
	printf("%d\n%d\n",st1->a,st1->b);

	free(st);
	return 0;
}

