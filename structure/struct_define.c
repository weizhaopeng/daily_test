#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a; 
	int b;
} test;

static test *fun(void)
{
	test *t = (test *)malloc(sizeof(test));
	t->a    = 3;
	t->b	= 4;
	return t;
}

int main (int argc, char **argv)
{
	test *t = fun();;
	
	printf("%d\n",t->a);
	free(t);
	return 0;
}
	
